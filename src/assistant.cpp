#include "includeall.hpp"

void HomeAssistantServer::setStatus(ServerStatus status) {
    this->status = status;
}

ServerStatus HomeAssistantServer::getStatus() {
    return this->status;
}
