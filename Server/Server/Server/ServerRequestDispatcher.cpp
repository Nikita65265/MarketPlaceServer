#include "ServerRequestDispatcher.h"

json ServerRequestDispatcher::getRequest(const json& msg)
{
	return "";
}


void ServerRequestDispatcher::sendMessage(METHODS method, const json& msg) {
	if		(method == Get)		getDataFromDataBase(msg);
	else if (method == Delete) 	deleteDataFromDataBase(msg);
	else if (method == Post)	postDataToDataBase(msg);
	else if (method == Put)		putDataToDataBase(msg);
	else if (method == Login)	loginClient(msg);
	else if (method == Logout)  logoutClient(msg);
	else assert("NO SUCH COMMAND");
}


json ServerRequestDispatcher::getDataFromDataBase(const json& msg)
{
	return "";
}


json ServerRequestDispatcher::deleteDataFromDataBase(const json& msg)
{
	return "";

}


json ServerRequestDispatcher::postDataToDataBase(const json& msg)
{
	return "";

}


json ServerRequestDispatcher::putDataToDataBase(const json& msg)
{
	return "";

}


json ServerRequestDispatcher::loginClient(const json& msg)
{
	return "";

}


json ServerRequestDispatcher::logoutClient(const json& msg)
{
	return "";

}

