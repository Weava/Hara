#include "Application.h"

#include "../platform/windows/MSWindow.cpp"
#include "Window.h"

namespace Hara {

    Application::Application() {}

    Application::~Application() {}

    void Application::run() {
        Window* window = new MSWindow();
        window->showWindow();
    }
}  // namespace Hara
