#include "level.hpp"

#include <format>

#include "error/conversion_error.hpp"


[[nodiscard]] std::string_view logging::level_to_string(level const& level) {
    switch (level) {
        case level::trace:
            return "trace";
        case level::debug:
            return "debug";
        case level::information:
            return "information";
        case level::warning:
            return "warning";
        case level::error:
            return "error";
    default:
            const auto str = std::format("Invalid level value: {}", static_cast<std::uint8_t>(level));
            throw error::conversion_error(str);
    }
}
