#include "handler.hpp"

#include "stdout_handler.hpp"


std::unique_ptr<logging::handling::handler> logging::handling::get_default_handler() {
    return std::make_unique<stdout_handler>();
}
