#pragma once

#include <GLFW/glfw3.h>

#include "../../core/Window.h"

namespace Hara {
    class MSWindow : public Window {
       public:
        MSWindow(const WindowProps& props);
        virtual ~MSWindow();

        void onUpdate() override;
        void setVSync(bool enabled) override;
        bool isVSyncEnabled() const override;

        inline void setEventCallback(const EventCallbackFn& callback) override {
            windowData.eventCallback = callback;
        }

       private:
        virtual void init(const WindowProps& props);
        virtual void shutdown();

       private:
        GLFWwindow* window;

        struct WindowData {
            std::string title;
            unsigned int width, height;
            bool isVSyncEnabled;

            EventCallbackFn eventCallback;
        };

        WindowData windowData;
    };
}  // namespace Hara