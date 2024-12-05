#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "ServerCommands.h"

using json = nlohmann::json;

class ServerRequestDispatcher
{
public:
 	json getRequest(const json& msg);
    void sendMessage(METHODS method, const json& msg);
 
private:
    json getDataFromDataBase(const json& msg);
    json deleteDataFromDataBase(const json& msg);
    json postDataToDataBase(const json& msg);
    json putDataToDataBase(const json& msg);

    json loginClient(const json& msg);
    json logoutClient(const json& msg);
};


