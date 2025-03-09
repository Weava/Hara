#pragma once

#include "spdlog.h"

namespace Hara {

    class Log {
       public:
        static void init();

        iniline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
            return coreLogger
        }

       private:
        static std::shared_ptr<spdlog::logger> coreLogger;
    };
}  // namespace Hara