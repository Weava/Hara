# Hara Engine

#### A small game engine project basing off of the Cherno's Hazel engine

## How to use

### Windows

1. Install [CMake](https://cmake.org/download/)

2. If you don't have Visual Studio installed, you can install the [latest version](https://visualstudio.microsoft.com/downloads/). If you prefer to use a non Visual Studio IDE to build you can simply install the [Visual Studio build tools](https://aka.ms/vs/17/release/vs_BuildTools.exe)

3. From any command line run `scripts/windows/BuildProject.bat`. No arguments will result in a `Debug` build, add either `Release` or `Dist` as an argument for those respective build types. 

4. If everything is good, the program should build and start on its own. At this point you should have solution files to use for Visual Studio.

#### Visual Studio 

Visual Studio does support CMake projects like this one. [Relevant docs here](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170)

**NOTE**: Visual Studio project files are GITIGNORED, so new CMake runs may destroy any project configurations you make within Visual Studio. If you do wish to edit project configurations
it is preferable to do so in the appropriate `CMakeLists.txt` file

#### MacOS

TBD

#### Linux

TBD