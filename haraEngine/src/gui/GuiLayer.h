#pragma once

#include "../core/Core.h"
#include "../core/Layer.h"

namespace Hara {
    class HARA_API GuiLayer : public Layer {
       public:
        GuiLayer();
        ~GuiLayer();

        void onAttach();
        void onDetach();
        void onUpdate();
        void onEvent(Event& event);
    };
}  // namespace Hara