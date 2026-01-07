#include "Wrapper.h"

extern "C" {
    void* CreateServer() { return nullptr; }
    
    int Terminate(void* serverPtr) { return 1; }
    
    int GetServerStatus(void* serverPtr) { return 1; }

    int StartServer(void* serverPtr, const char** args, int count) { return 1; }

}