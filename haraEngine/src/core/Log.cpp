#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hara {
    std::shared_ptr<spdlog::logger> Log::coreLogger;

    void Log::init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        coreLogger = spdlog::stdout_color_mt("Hara");
        coreLogger->set_level(spdlog::level::trace);
    }
}  // namespace Hara