#include "stdout_handler.hpp"

#include <algorithm>
#include <iostream>
#include <sstream>

#include "../level.hpp"


logging::handling::stdout_handler::stdout_handler()
    : stdout_handler(level::debug, {}, format::get_default_formatter())
{}

logging::handling::stdout_handler::stdout_handler(
    const logging::level level,
    std::vector<filter::filter> filters,
    std::unique_ptr<format::formatter> formatter
) :
    level(level),
    filters(std::move(filters)),
    formatter(std::move(formatter))
{}

void logging::handling::stdout_handler::dispatch_record(const record &record) const noexcept {
    if (!level_allows_level(this->level, record.level)) return;

    for (const auto& filter : this->filters) {
        if (filter(record)) return;
    }

    const std::string formatted_record = this->formatter->format_record(record);
    std::cout << formatted_record << std::endl;
}

