#include "includeall.hpp"

void HomeAssistantServer::setStatus(ServerStatus status) {
    this->status = status;
}

ServerStatus HomeAssistantServer::getStatus() {
    return this->status;
}

void HomeAssistantServer::start(std::string args[]) {};  // To make later
bool HomeAssistantServer::restart()                 {return 0;};  // To make later
void HomeAssistantServer::terminate()               {};  // To make later
