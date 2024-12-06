#include "ServerRequestDispatcher.h"

json ServerRequestDispatcher::getRequest(const json& msg)
{
	return "";
}


json ServerRequestDispatcher::sendMessage(METHODS method, const json& msg) {
	if		(method == METHODS::Get)	return getDataFromDataBase(msg);
	else if (method == METHODS::Delete) return deleteDataFromDataBase(msg);
	else if (method == METHODS::Post)	return postDataToDataBase(msg);
	else if (method == METHODS::Put)	return putDataToDataBase(msg);
	else if (method == METHODS::Login)	return loginClient(msg);
	else if (method == METHODS::Logout) return logoutClient(msg);
	
	assert("NO SUCH COMMAND");
	return "";
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

