#pragma once

#include "../event/Event.h"
#include "Core.h"

namespace Hara {

    class HARA_API Layer {
       public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate() {}
        virtual void onEvent(Event& event) {}

        inline const std::string& getName() const { return debugName; }

       protected:
        std::string debugName;
    };
}  // namespace Hara