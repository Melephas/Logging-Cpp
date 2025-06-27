#include "logging/logging.hpp"



int main() {
    const auto log = logging::logger::get_logger();

    log->trace("Created default logger");

    log->debug("This is a debug logger");

    log->info("Hello world!");

    log->warn("About to quit!");

    log->error("An error!");

    return 0;
}
