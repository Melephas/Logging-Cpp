#pragma once

#include <cstdint>
#include <string_view>


namespace logging {
    enum class level : std::uint8_t {
        trace,
        debug,
        information,
        warning,
        error
    };

    // Can the object with level `base` process a record with level `other`
    [[nodiscard]] inline bool level_allows_level(level const& base, level const& other) noexcept {
        return other >= base;
    }

    // Convert a level to a textual representation
    [[nodiscard]] std::string_view level_to_string(level const& level);
}
