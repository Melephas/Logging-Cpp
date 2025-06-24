#include "logger.hpp"

#include "simple_logger.hpp"


std::unique_ptr<logging::logger::logger> logging::logger::get_default_logger() {
    return std::make_unique<simple_logger>();
}
