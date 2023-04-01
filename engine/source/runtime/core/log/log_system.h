#pragma once

#include <cstdint>

namespace Piccolo
{
    class LogSystem final
    {
    public:
        enum class LogLevel : uint8_t
        {
            debug,
            info,
            warn,
            error,
            fatal
        };

    public:
        LogSystem();
        ~LogSystem();

        template<typename... TARGS>
        void log(LogLevel level, TARGS&&... args)
        {

        }
    };

} // namespace Piccolo
