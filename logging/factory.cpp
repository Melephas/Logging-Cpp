#include "factory.hpp"

#include <algorithm>
#include "handling/file_handler.hpp"


std::unique_ptr<logging::factory::logger_interface> logging::factory::get_logger(const std::string_view hints) {
    std::unordered_map<std::string_view, level> lvl_map = {
        { "trace", level::trace },
        { "debug", level::debug },
        { "info", level::information },
        { "warn", level::warning },
        { "error", level::error }
    };

    const auto lvl = std::ranges::find_if(
        lvl_map,
        [&](const auto& x) {
            auto name = std::get<0>(x);
            return hints.contains(name);
        }
    );

    return std::make_unique<logger_type>(
        lvl->second,
        std::vector<filter::filter>(),
        get_handler(hints, lvl->second)
    );

}

std::unique_ptr<logging::factory::handler_interface> logging::factory::get_handler(const std::string_view hints, level handler_level) {
    if (hints.contains("stdout")) {
        return std::make_unique<handling::stdout_handler>(
            handler_level,
            std::vector<filter::filter>(),
            get_formatter(hints)
        );
    }

    // Find filepath in hints
    std::string_view file_tag = "file:";
    std::string file_path = std::ranges::search(hints, file_tag).end();

    return std::make_unique<handling::file_handler>(
        handler_level,
        std::vector<filter::filter>(),
        get_formatter(hints),
        file_path
    );
}

std::unique_ptr<logging::factory::formatter_interface> logging::factory::get_formatter(const std::string_view hints) {
    return std::make_unique<formatter_type>();
}
