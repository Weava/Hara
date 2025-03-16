#pragma once

#include "Core.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace Hara {

    class Log {
       public:
        HARA_API static void init();

        inline static HARA_API std::shared_ptr<spdlog::logger>&
        getCoreLogger() {
            return coreLogger;
        };

       private:
        static HARA_API std::shared_ptr<spdlog::logger> coreLogger;
    };
}  // namespace Hara

#define CORE_LOG_TRACE(...) ::Hara::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CORE_LOG_INFO(...) ::Hara::Log::getCoreLogger()->info(__VA_ARGS__)
#define CORE_LOG_WARN(...) ::Hara::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_LOG_ERROR(...) ::Hara::Log::getCoreLogger()->error(__VA_ARGS__)