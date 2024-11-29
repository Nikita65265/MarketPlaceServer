#include "ServerRequestDispatcher.h"

json ServerRequestDispatcher::getRequest(const json& msg)
{
}


void ServerRequestDispatcher::sendMessage(const json& msg) {
	std::string command = msg[commands.Method];

	if		(command == methods.Get)	getDataFromDataBase(msg);
	else if (command == methods.Delete) deleteDataFromDataBase(msg);
	else if (command == methods.Post)	postDataToDataBase(msg);
	else if (command == methods.Put)	putDataToDataBase(msg);
	else if (command == methods.Login)	loginClient(msg);
	else if (command == methods.Logout) logoutClient(msg);

	else assert("NO SUCH COMMAND");
}


json ServerRequestDispatcher::getDataFromDataBase(const json& msg)
{

}


json ServerRequestDispatcher::deleteDataFromDataBase(const json& msg)
{

}


json ServerRequestDispatcher::postDataToDataBase(const json& msg)
{

}


json ServerRequestDispatcher::putDataToDataBase(const json& msg)
{

}


json ServerRequestDispatcher::loginClient(const json& msg)
{

}


json ServerRequestDispatcher::logoutClient(const json& msg)
{

}

