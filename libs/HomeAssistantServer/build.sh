# -fPIC: force Position Independent Code (this is required when compiling shared libraries)
# -shared: Creates a shared library (.so)
# -I: Include directories
# -o: Specifies the output filename


g++ -fPIC -shared -I include \
    src/Wrapper.cpp \
    src/assistant.cpp \
    src/feature.cpp \
    -o HomeAssistantServer.so
