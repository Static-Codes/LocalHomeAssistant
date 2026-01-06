#pragma once

// Native headers (unchanged)
#include "./includeall.hpp"

#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Collections::Generic;

//
// Managed enums (mirrors of native enums)
//

public enum class ManagedServerStatus
{
    Inactive   = 1,
    Running   = 2,
    Restarting = 3,
    Terminated = 4
};

public enum class ManagedFeatureName
{
    WeatherForecast = 0,
    WebSearch       = 1,
    StockPrices     = 2
};

public enum class ManagedFeatureStatus
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

public ref class ManagedFeature
{
private:
    Feature* native;

internal:
    ManagedFeature(Feature* feature)
        : native(feature)
    {}

public:
    property ManagedFeatureName Name
    {
        ManagedFeatureName get()
        {
            return static_cast<ManagedFeatureName>(native->name);
        }
    }

    property ManagedFeatureStatus Status
    {
        ManagedFeatureStatus get()
        {
            return static_cast<ManagedFeatureStatus>(native->getStatus());
        }
        void set(ManagedFeatureStatus value)
        {
            native->setStatus(static_cast<FeatureStatus>(value));
        }
    }
};

//
// Managed HomeAssistantServer wrapper
//

public ref class ManagedHomeAssistantServer
{
private:
    HomeAssistantServer* native;

public:
    ManagedHomeAssistantServer()
    {
        native = new HomeAssistantServer();
    }

    ~ManagedHomeAssistantServer()
    {
        this->!ManagedHomeAssistantServer();
    }

    !ManagedHomeAssistantServer()
    {
        delete native;
        native = nullptr;
    }

    ManagedServerStatus GetStatus()
    {
        return static_cast<ManagedServerStatus>(native->getStatus());
    }

    void SetStatus(ManagedServerStatus status)
    {
        native->setStatus(static_cast<ServerStatus>(status));
    }

    void Start(array<String^>^ args)
    {
        // Convert managed strings to std::string
        std::vector<std::string> nativeArgs;
        for each (String^ s in args)
        {
            nativeArgs.push_back(
                msclr::interop::marshal_as<std::string>(s)
            );
        }

        native->start(nativeArgs.data());
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
