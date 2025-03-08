#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>

#include <iostream>

#include "Hara.h"
#include "engine/Engine.h"
#include "platform/windows/MSWindow.cpp"

using namespace Hara;

int main() {
    // Engine::Engine engine;
    // try {
    //     engine.run();
    // } catch (std::exception e) {
    //     std::cout << "Game engine closed";
    //     return EXIT_FAILURE;
    // }

    // return EXIT_SUCCESS;

    Window *window = new MSWindow();
    window->showWindow();
}