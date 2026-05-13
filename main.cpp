#include "logging/logging.hpp"


int main() {
    const auto log = logging::factory::get_logger("trace stdout");

    log->trace("Created logger from factory");

    log->debug("This is a debug logger");

    log->info("Hello world!");

    log->warn("About to quit!");

    log->error("An error!");

    return 0;
}
