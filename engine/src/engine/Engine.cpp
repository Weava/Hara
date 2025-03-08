#include "Engine.h"

#include <iostream>
#include <stdexcept>

namespace GameEngine {

    void Engine::run() {
        if (!init())
            throw std::runtime_error("Failed initializing game engine");
        renderLoop();
    }

    bool Engine::init() { return true; }

    void Engine::renderLoop() {
        while (isRunning) {
            std::cout << "running";
        }
    }

    void Engine::cleanup() {}
}  // namespace GameEngine