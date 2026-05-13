#include "logger.hpp"

#include "simple_logger.hpp"


std::unique_ptr<logging::logger::logger> logging::logger::get_logger(level lvl = level::debug) {
    return std::make_unique<simple_logger>(
        lvl,
        std::vector<filter::filter>(),
        handling::get_handler("stdout")
    );
}

std::unique_ptr<logging::logger::logger> logging::logger::get_logger(std::string_view target) {
    return std::make_unique<simple_logger>(
        level::debug,
        std::vector<filter::filter>(),
        handling::get_handler(target)
    );
}
