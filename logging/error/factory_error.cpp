#include "factory_error.hpp"

logging::error::factory_error::factory_error(const char *message)
    : runtime_error(message), message(message) {}

logging::error::factory_error::factory_error(const std::string &message)
    : runtime_error(message), message(message) {}

const char *logging::error::factory_error::what() const noexcept {
    return runtime_error::what();
}

std::string logging::error::factory_error::description() const noexcept {
    return this->message;
}
