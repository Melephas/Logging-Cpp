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

    [[nodiscard]] inline bool level_allows_level(const level &base, const level &secondary) noexcept {
        switch (base) {
            case level::trace:
                return true;
            case level::debug:
                return secondary != level::trace;
            case level::information:
                return (secondary == level::information) || (secondary == level::warning) || (secondary == level::error);
            case level::warning:
                return (secondary == level::warning) || (secondary == level::error);
            case level::error:
                return secondary == level::error;
            default:
                return false;
        }
    }

    [[nodiscard]] std::string_view level_to_string(const level& level);
}
