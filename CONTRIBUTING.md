# Building the C++ Files
To build the C++ source code files into a **Dynamic Library** (DLL) that C# code can later use, please run `build.bat` in **Command Prompt**, and then
run `cl /clr /LD /I include src\Wrapper.cpp src\assistant.cpp src\feature.cpp /Fe:MyLibrary.Cli.dll`.
You will then see a `MyLibrary.Cli.dll` file. Feel free to rename it as you wish (keeping the `.dll` extension).
You can now use the DLL file in your C# code.