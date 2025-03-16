#include "Application.h"

#include <GLFW/glfw3.h>

#include "../event/ApplicationEvent.h"
#include "../event/Event.h"
#include "Log.h"

namespace Hara {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application() {
        window = std::unique_ptr<Window>(Window::create());
        window->setEventCallback(BIND_EVENT_FN(onEvent));
    }

    Application::~Application() {}

    void Application::run() {
        while (isRunning) {
            window->onUpdate();
        }
    }

    bool Application::onWindowClose(WindowCloseEvent closeEvent) {
        isRunning = false;
        return true;
    }

    void Application::onEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
        CORE_LOG_INFO(e.toString());
    }

}  // namespace Hara
