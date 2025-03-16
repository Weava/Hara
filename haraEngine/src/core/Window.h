#pragma once

#include "../event/Event.h"
#include "../hpch.h"
#include "Core.h"

namespace Hara {

    struct WindowProps {
        std::string title;
        unsigned int width, height;

        WindowProps(const std::string& title = "Hara",
                    unsigned int width = 1280, unsigned int height = 720)
            : title(title), width(width), height(height) {}
    };
    class HARA_API Window {
       public:
        using EventCallbackFn = std::function<void(Event&)>;
        virtual ~Window() {}

        virtual void onUpdate() = 0;

        virtual void setEventCallback(const EventCallbackFn& callback) = 0;
        virtual void setVSync(bool enabled) = 0;
        virtual bool isVSyncEnabled() const = 0;

        static Window* create(const WindowProps& props = WindowProps());
    };
}  // namespace Hara