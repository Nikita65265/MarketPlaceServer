#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

using namespace boost::asio;

class Server : public boost::enable_shared_from_this<Server> {
	using ptr = boost::shared_ptr<Server>;
	using error_code = boost::system::error_code;
public:
	Server(short port);

	void runServer();
	void handle_accept(ptr connection, const error_code& err);

	static ptr createNewConnection();


private:
	bool isWorkServer = false;
	ip::tcp::socket tcpSocket;

	const static int msgSize = 1024;
	char readBuffer[msgSize] = { 0 };
	char writeBuffer[msgSize] = { 0 };

	// Управление работой сервера
	void startWork();
	void stopWork();
	
	// Счиытвание данных
	void do_read();
	void on_read(const error_code& err, size_t bytes);
	size_t read_complete(const error_code& err, size_t bytes);
	
	// Запись данных
	void do_write(std::string_view msg);
	void on_write(const error_code& err, size_t bytes);

	ip::tcp::socket& getSocket();
};

