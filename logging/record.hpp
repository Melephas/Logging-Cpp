#pragma once

#include <chrono>
#include <string>
#include <string_view>

#include "level.hpp"

#include "time/time.hpp"


namespace logging {
    struct record {
        std::string message;
        std::unique_ptr<time::time> time;
        level record_level;

        // Create a new log record with the date and time set during creation
        record(level record_level, std::string_view message) noexcept;
    };
}
