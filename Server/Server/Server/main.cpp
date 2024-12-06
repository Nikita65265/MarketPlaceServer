#include <iostream>
#include <nlohmann/json.hpp>

#include "Server.h"

using json = nlohmann::json;

int main() {
    std::cout << "START" << std::endl;

    boost::shared_ptr<Server> server(new Server(8001));
    server->runServer();
}
