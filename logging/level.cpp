#include "level.hpp"

#include <sstream>

#include "error/conversion_error.hpp"


[[nodiscard]] std::string_view logging::level_to_string(const level& level) {
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
            std::stringstream string_builder;
            string_builder << "Invalid level value: " << static_cast<std::uint8_t>(level);
            throw error::conversion_error(string_builder.str());
    }
}
