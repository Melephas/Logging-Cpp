#include "file_handler.hpp"

#include <fstream>
#include <random>


logging::handling::file_handler::file_handler(const std::string& file_path) : file_handler(
        level::debug,
        {},
        format::get_default_formatter(),
        file_path
    ) {}

logging::handling::file_handler::file_handler(
    const logging::level level,
    std::vector<filter::filter> filters,
    std::unique_ptr<format::formatter> formatter,
    const std::string& file_path
) :
    level(level),
    filters(std::move(filters)),
    formatter(std::move(formatter))
{
    this->file_out = std::fopen(file_path.c_str(), "a");
}

logging::handling::file_handler::~file_handler() {
    std::fclose(this->file_out);
}

void logging::handling::file_handler::dispatch_record(const record &record) const noexcept {
    if (!level_allows_level(this->level, record.level)) return;

    for (const auto& filter : this->filters) {
        if (filter(record)) return;
    }

    const std::string formatted_record = this->formatter->format_record(record);
    std::fprintf(this->file_out, "%s\n", formatted_record.c_str());
}
