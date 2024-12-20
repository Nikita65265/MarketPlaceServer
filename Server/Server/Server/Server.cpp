#include "Server.h"

#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include <boost/array.hpp>

#include "ServerRequestDispatcher.h"

io_context server_context;
ip::tcp::acceptor acceptor(server_context, ip::tcp::endpoint(ip::tcp::v4(), 8001));

Server::Server(short port) :
	tcpSocket(server_context)
{
}


void Server::runServer() 
{
	ptr connection = Server::createNewConnection();
	acceptor.async_accept(connection->getSocket(), 
		boost::bind(&Server::handle_accept, shared_from_this(), connection, _1));
	server_context.run();
}


void Server::handle_accept(ptr connection, const error_code& err)
{
	std::cout << "new client\n";
	connection->startWork();

	ptr newConnection = Server::createNewConnection();
	acceptor.async_accept(newConnection->getSocket(),
		boost::bind(&Server::handle_accept, shared_from_this(), newConnection, _1));
}


Server::ptr Server::createNewConnection()
{
	return boost::make_shared<Server>(8001);
}


ip::tcp::socket& Server::getSocket()
{
	return tcpSocket;
}


void Server::startWork()
{
	isWorkServer = true;
	do_read();
}


void Server::stopWork()
{
	if (!isWorkServer) return;
	isWorkServer = false;

	std::cout << "remove client\n";
	tcpSocket.close();
}


void Server::do_read() {
	async_read(tcpSocket, boost::asio::buffer(readBuffer),
		bind(&Server::read_complete, shared_from_this(), _1, _2),
		bind(&Server::on_read, shared_from_this(), _1, _2));
}


size_t Server::read_complete(const error_code& err, size_t bytes)
{
	if (err) return 0;
	
	auto myFind = [](const char* ch, const size_t& bytes) -> size_t {
		char finderSymb = '\n';
		int counter = 0;
		for (int i = bytes; i >= 0; --i) {
			if (ch[i] == finderSymb) {
				counter++;
				if (counter == 4) return bytes;

				if (finderSymb == '\n') finderSymb = '\r';
				else					finderSymb = '\n';
			}
			else {
				counter = 0;
			}
		}

		return 0;
	};

	return !myFind(readBuffer, bytes);
}


void Server::on_read(const error_code& err, size_t bytes)
{
	if (err) stopWork();
	if (!isWorkServer) return;
	if (bytes < 4) {
		do_read();
		return;
	}

	std::string msg(readBuffer, bytes);

	for (int i = 0; i < bytes; i++) readBuffer[i] = '0';

	msg.resize(bytes - 4);

	std::cout << msg << " bytes: " << bytes << std::endl;
	do_write("Response to msg: " + msg);
}


void Server::do_write(std::string_view msg)
{
	if (!isWorkServer) return;
	std::copy(msg.begin(), msg.end(), writeBuffer);
	tcpSocket.async_write_some(buffer(writeBuffer, msg.size()),
		boost::bind(&Server::on_write, shared_from_this(), _1, _2));
}


void Server::on_write(const error_code& err, size_t bytes)
{
	do_read();
}