#pragma once

#include "status.hpp"
#include "feature.hpp"

#include <vector>
#include <string>

class HomeAssistantServer {
    public:
        ServerStatus getStatus();
        void start(std::string args[]);
        bool restart();
        void terminate();
        void setStatus(ServerStatus status);
    private:
        ServerStatus status = ServerStatus::Inactive;
        std::vector<Feature> availableFeatures;
};
