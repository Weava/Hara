#include "Application.h"

#include <GLFW/glfw3.h>
#include <imgui.h>

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
            for (Layer* layer : layerStack) {
                layer->onUpdate();
            }
            window->onUpdate();
        }
    }

    void Application::pushLayer(Layer* layer) { layerStack.pushLayer(layer); }

    void Application::pushOverlay(Layer* layer) {
        layerStack.pushOverlay(layer);
        layer->onAttach();
    }

    bool Application::onWindowClose(WindowCloseEvent closeEvent) {
        isRunning = false;
        return true;
    }

    void Application::onEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));
        CORE_LOG_INFO(e.toString());

        for (auto it = layerStack.end(); it != layerStack.begin();) {
            (*--it)->onEvent(e);
            if (e.isHandled) {
                break;
            }
        }
    }

}  // namespace Hara
