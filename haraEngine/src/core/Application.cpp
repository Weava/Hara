#include "Application.h"

#include "../platform/windows/MSWindow.cpp"
#include "Log.h"
#include "Window.h"

namespace Hara {

    Application::Application() {}

    Application::~Application() {}

    void Application::run() {
        CORE_LOG_INFO("WINDOW OPENED");
        Window* window = new MSWindow();
        window->showWindow();
    }
}  // namespace Hara
