#include "Application.h"

#include "../event/ApplicationEvent.h"
#include "../platform/windows/MSWindow.cpp"
#include "Log.h"
#include "Window.h"

namespace Hara {

    Application::Application() {}

    Application::~Application() {}

    void Application::run() {
        CORE_LOG_INFO("WINDOW OPENED");
        WindowResizeEvent e(1280, 720);
        if (e.isInCategory(EventCategoryApplication)) {
            CORE_LOG_TRACE(e.toString());
        }
        if (e.isInCategory(EventCategoryInput)) {
            CORE_LOG_TRACE(e.toString());
        }
        Window* window = new MSWindow();
        window->showWindow();
    }
}  // namespace Hara
