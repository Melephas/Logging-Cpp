#include "conversion_error.hpp"

logging::error::conversion_error::conversion_error(const char *message)
    : runtime_error(message), message(message) {}

logging::error::conversion_error::conversion_error(const std::string &message)
    : runtime_error(message.c_str()), message(message) {}

const char *logging::error::conversion_error::what() const noexcept {
    return runtime_error::what();
}

std::string logging::error::conversion_error::description() const noexcept {
    return this->message;
}

