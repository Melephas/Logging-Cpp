#include "simple_logger.hpp"

#include <utility>

logging::logger::simple_logger::simple_logger() :
    simple_logger(level::debug, {}, {}) {
    this->handlers.push_back(handling::get_default_handler());
}

logging::logger::simple_logger::simple_logger(
    const logging::level level,
    std::vector<std::unique_ptr<filter::filter>> filters,
    std::vector<std::unique_ptr<handling::handler>> handlers
) :
    level(level),
    filters(std::move(filters)),
    handlers(std::move(handlers)) {
}

void logging::logger::simple_logger::handle_record(const record &record) const {
    if (!level_allows_level(this->level, record.level)) return;

    for (const auto &filter : this->filters) {
        if (filter->should_drop(record)) return;
    }

    for (const auto &handler : this->handlers) {
        handler->dispatch_record(record);
    }
}

void logging::logger::simple_logger::trace(const std::string_view message) const {
    this->handle_record(record(level::trace, message));
}

void logging::logger::simple_logger::debug(const std::string_view message) const {
    this->handle_record(record(level::debug, message));
}

void logging::logger::simple_logger::info(const std::string_view message) const {
    this->handle_record(record(level::information, message));
}

void logging::logger::simple_logger::warn(const std::string_view message) const {
    this->handle_record(record(level::warning, message));
}

void logging::logger::simple_logger::error(const std::string_view message) const {
    this->handle_record(record(level::error, message));
}
