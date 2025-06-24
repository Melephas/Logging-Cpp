#include "formatter.hpp"

#include <memory>

#include "simple_formatter.hpp"


std::unique_ptr<logging::format::formatter> logging::format::get_default_formatter() noexcept {
    return std::make_unique<simple_formatter>();
}
