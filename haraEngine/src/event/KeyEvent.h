
#pragma once

#include "Event.h"

namespace Hara {

    class HARA_API KeyEvent : public Event {
       public:
        inline int getKeyCode() const { return keyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
       protected:
        KeyEvent(int keycode) : keyCode(keycode) {}

        int keyCode;
    };

    class HARA_API KeyPressedEvent : public KeyEvent {
       public:
        KeyPressedEvent(int keycode, int repeatCount)
            : KeyEvent(keycode), repeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return repeatCount; }

        std::string toString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount
               << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
       private:
        int repeatCount;
    };

    class HARA_API KeyReleasedEvent : public KeyEvent {
       public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

        std::string toString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}  // namespace Hara