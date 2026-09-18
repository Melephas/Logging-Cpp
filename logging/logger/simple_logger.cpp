#include "simple_logger.hpp"

#include <utility>

logging::logger::simple_logger::simple_logger(const level logger_level, std::vector<filter::filter> filters, std::unique_ptr<handling::handler> handler)
    : logger_level { logger_level }, filters(std::move(filters)), handler(std::move(handler)) {}

void logging::logger::simple_logger::handle_record(record const& record) const {
    if (!level_allows_level(this->logger_level, record.record_level)) return;

    for (const auto &filter : this->filters) {
        if (filter(record)) return;
    }

    this->handler->dispatch_record(record);
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
