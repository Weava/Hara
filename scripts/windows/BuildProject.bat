@echo off
set buildType=%1
set tempType=

IF %buildType%==Dist set tempType=Dist
IF %buildType%==Release set tempType=Release
IF %buildType%==Debug set tempType=Debug
IF %buildType%==dist set tempType=Dist
IF %buildType%==release set tempType=Release
IF %buildType%==debug set tempType=Debug
IF [%buildType%]==[] set tempType=Debug

IF [%tempType%]==[] set tempType=Debug

set buildType=%tempType%

REM Generating build files...
cmake -DCMAKE_INSTALL_PREFIX:STRING=build -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE=%buildType% --no-warn-unused-cli -SC:/dev/Hara -Bc:/dev/Hara/build -G "Visual Studio 17 2022"

REM Building Stage application...
cmake --build c:/dev/Hara/build --config %buildType% --target ALL_BUILD -j 34 --

REM Launching Stage...
start %~dp0\..\..\build\stage\%buildType%\Stage.exe