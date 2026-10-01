#ifndef NO_STD_CHRONO

#include "chrono_time.hpp"

#include <format>

std::string logging::time::chrono_time::format() const {
    auto zt = std::chrono::zoned_time {
        std::chrono::current_zone(),
        std::chrono::time_point_cast<std::chrono::seconds>(time_point)
    };

    return std::format("{:%FT%T%z}", zt);
}

#endif
