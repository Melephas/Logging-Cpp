#pragma once

#include <chrono>
#include <string>
#include <string_view>

#include "level.hpp"


namespace logging {
    struct record {
        using time_t = std::chrono::time_point<std::chrono::system_clock>;

        std::string message;
        time_t time;
        level record_level;

        // Create a new log record with the date and time set during creation
        record(level record_level, std::string_view message) noexcept;
    };
}
