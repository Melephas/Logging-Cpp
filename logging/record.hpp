#pragma once

// ReSharper disable once CppUnusedIncludeDirective
#include <ctime>
#include <string>
#include <string_view>

#include "level.hpp"


namespace logging {
    struct record {
        std::string message;
        std::time_t time;
        level level;

        // Create a new log record with the date and time set during creation
        record(logging::level level, std::string_view message) noexcept;
    };
}
