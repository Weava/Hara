#pragma once

#include "../event/ApplicationEvent.h"
#include "../event/Event.h"
#include "Core.h"
#include "Window.h"

namespace Hara {
    class HARA_API Application {
       public:
        Application();
        ~Application();

        void run();

        void onEvent(Event& e);

       private:
        bool onWindowClose(WindowCloseEvent closeEvent);
        std::unique_ptr<Window> window;
        bool isRunning = true;
    };

    Application* createApplication();
}  // namespace Hara