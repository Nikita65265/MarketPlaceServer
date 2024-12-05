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
	connection->startWork();
}


Server::ptr Server::createNewConnection()
{
	return boost::make_shared<Server>(12345);
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

	std::string data(readBuffer, bytes);

	return  data.find("\r\n\r\n") != std::string::npos;
}


void Server::on_read(const error_code& err, size_t bytes)
{
	if (err) stopWork();
	if (!isWorkServer) return;

	std::string msg(readBuffer, bytes);


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

}