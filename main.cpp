#include "logging/logger/logger.hpp"


int main() {
    const auto log = logging::logger::get_default_logger();
    log->trace("Created default logger");

    log->info("Hello world!");

    log->warn("About to quit!");

    return 0;
}
