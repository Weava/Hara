# GameEngine (I don't have a name yet)


## How to use

### Windows

1. Install [Msys2](https://www.msys2.org/).

2. Once installed, open your Msys2 instance.

3. Enter `pacman -Syu` to update your pacman instance to latest version. 

4. Install `mingw-w64` toolchain using by entering `pacman -S mingw-w64-ucrt-x86_64-toolchain` in Msys2 terminal.

5. Open your new MINGW instance (you can now search in windows start menu, with the phrase `mingw`)

6. With MINGW instance open, now run the following commands: 
    ```
    pacman -S mingw-w64-ucrt-x86_64-gsl
    pacman -S mingw-w64-ucrt-x86_64-gcc
    pacman -S mingw-w64-ucrt-x86_64-cmake
    ```

7. Confirm g++ was installed with `g++ -v`; confirm cmake was installed with `cmake -version`

8. If you plan on using Visual Studio Code as a build & debug tool, ignore this and future steps and refer to Visual Studio Code section below. 

9. Run `cmake -G "Unix Makefiles"`

10. Run `make`

This should output a build folder containing `GameEngine.exe` that you can then run

### Visual Studio Code

1. Install the [C/C++ Tools for VSC](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

2. Install the [CMake tools for VSC](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

3. Create a `launch.json` file with the following configuration:
    ```
        {
            "name": "Game Engine",
            "cwd": "${workspaceFolder}",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/GameEngine.exe",
            "console": "externalTerminal"
        }
    ```

You should be able to build & launch within VSC after following these steps

#### MacOS

TBD

#### Linux

TBD