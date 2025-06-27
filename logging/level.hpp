#pragma once

#include <string_view>


namespace logging {
    enum class level {
        trace,
        debug,
        information,
        warning,
        error
    };

    // Can the object with level `base` process a record with level `other`
    [[nodiscard]] inline bool level_allows_level(const level &base, const level &other) noexcept {
        switch (base) {
            case level::trace:
                return true;
            case level::debug:
                return other != level::trace;
            case level::information:
                return (other == level::information) || (other == level::warning) || (other == level::error);
            case level::warning:
                return (other == level::warning) || (other == level::error);
            case level::error:
                return other == level::error;
            default:
                return false;
        }
    }

    // Convert a level to a textual representation
    [[nodiscard]] std::string_view level_to_string(const level& level);
}
