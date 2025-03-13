#pragma once

#include "Core.h"

namespace Hara {
    class HARA_API Application {
       public:
        Application();
        ~Application();

        void run();
    };

    Application* createApplication();
}  // namespace Hara