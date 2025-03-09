#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hara {

    class Log {
       public:
        static void HARA_API init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
            return coreLogger;
        };

       private:
        static std::shared_ptr<spdlog::logger> coreLogger;
    };
}  // namespace Hara