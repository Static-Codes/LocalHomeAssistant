#pragma once
#include "./includeall.hpp"
#include <string>
#include <vector>

// Stopping Clangd from screaming at me for not being on Windows - Static
#if defined(_WIN32)
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

enum class ManagedServerStatus
{
    Inactive   = 1,
    Running   = 2,
    Restarting = 3,
    Terminated = 4
};

enum class ManagedFeatureName
{
    WeatherForecast = 0,
    WebSearch       = 1,
    StockPrices     = 2
};

enum class ManagedFeatureStatus
{
    Available              = 0,
    CurrentlyBroken        = 1,
    Finished               = 2,
    InProgress             = 3,
    TemporarilyUnavailable = 4
};

//
// Managed Feature wrapper
//

class ManagedFeature
{
    private: 
        Feature* native;
        
    public:
        ManagedFeature(Feature* feature) : native(feature) { }

    ManagedFeatureName GetName() {
        return static_cast<ManagedFeatureName>(native->name);
    };

    ManagedFeatureStatus GetStatus()
    {
        return static_cast<ManagedFeatureStatus>(native->getStatus());
    };

    void set(ManagedFeatureStatus value)
    {
        native->setStatus(static_cast<FeatureStatus>(value));
    };
};

//
// Managed HomeAssistantServer wrapper
//

class ManagedHomeAssistantServer
{
    private:
        HomeAssistantServer* native;

    public:
        ManagedHomeAssistantServer() {
            native = new HomeAssistantServer();
        }
        
        // Standard destructor as opposed to the Windows specific one, previous here - Static
        ~ManagedHomeAssistantServer() = default;
        
        
        // !ManagedHomeAssistantServer()
        // {
        //     delete native;
        //     native = nullptr;
        // }

        // Using a reference to the pointer to avoid syntax issues - Static
        ManagedHomeAssistantServer(const ManagedHomeAssistantServer&) = delete;

        ManagedServerStatus GetStatus()
        {
            return static_cast<ManagedServerStatus>(native->getStatus());
        }

        void SetStatus(ManagedServerStatus status)
        {
            native->setStatus(static_cast<ServerStatus>(status));
        }
        
        // Using the native c++ string vector as opposed to C# style string array
        void Start(std::vector<std::string> args)
        {
            native->start(args.data());
        }

        bool Restart()
        {
            return native->restart();
        }

        void Terminate()
        {
            native->terminate();
        }
};

// This is annoying but this is the cost of cross platform development - Static
extern "C" {
    // Using void* as a generic handle to the c++ object
    EXPORT void* CreateServer();
    EXPORT int Terminate(void* serverPtr);
    EXPORT int GetServerStatus(void* serverPtr);
    EXPORT int StartServer(void* serverPtr, const char** args, int count);
}