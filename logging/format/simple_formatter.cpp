#include "simple_formatter.hpp"

#include <iomanip>
#include <sstream>

#include "../error/conversion_error.hpp"

logging::format::simple_formatter::simple_formatter() noexcept {
    this->level_format_table = {
        {level::trace,       "TRC"},
        {level::debug,       "DBG"},
        {level::information, "INF"},
        {level::warning,     "WRN"},
        {level::error,       "ERR"}
    };

    this->time_format_string = "%FT%T%z";
}

std::string logging::format::simple_formatter::format_record(const record &record) const noexcept {
    const auto level_string = this->format_level(record.level);
    const auto time_string = this->format_time(record.time);

    std::stringstream builder;
    builder << time_string << " | " << level_string << " | " << record.message;

    return builder.str();
}

std::string logging::format::simple_formatter::format_level(const level &level) const {
    if (!this->level_format_table.contains(level)) {
        std::stringstream error_builder;
        error_builder << "Invalid level value (" << static_cast<std::uint8_t>(level) << ")";

        throw error::conversion_error(error_builder.str());
    }

    return this->level_format_table.at(level);
}

std::string logging::format::simple_formatter::format_time(const std::time_t &time) const { // NOLINT(*-convert-member-functions-to-static)
    const std::tm *local_time = std::localtime(&time);
    char formatted_time[256] = {};
    const std::size_t bytes_written = std::strftime(
        reinterpret_cast<char *>(&formatted_time),
        255,
        this->time_format_string.c_str(),
        local_time
    );

    if (bytes_written == 0) {
        throw error::conversion_error("Failed to format time struct");
    }

    std::string ret(formatted_time, bytes_written);
    return ret;
}

