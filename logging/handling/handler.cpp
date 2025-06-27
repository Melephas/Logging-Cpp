#include "handler.hpp"

#include "file_handler.hpp"
#include "stdout_handler.hpp"


std::unique_ptr<logging::handling::handler> logging::handling::get_handler(const std::string_view target) {
    if (target == "stdout") {
        return std::make_unique<stdout_handler>();
    }

    return std::make_unique<file_handler>(std::string(target));
}
