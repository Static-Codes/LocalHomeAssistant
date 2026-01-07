#pragma once
#include "./includeall.hpp"

// Stopping Clangd from screaming at me for not being on Windows - Static
#if defined(_WIN32)
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

// This is annoying but this is the cost of cross platform development - Static
extern "C" {
    // Using void* as a generic handle to the c++ object
    EXPORT void* CreateServer();
    EXPORT int Terminate(void* serverPtr);
    EXPORT int GetServerStatus(void* serverPtr);
    EXPORT int StartServer(void* serverPtr, const char** args, int count);
}