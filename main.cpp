#include "logging/logging.hpp"


int main() {
    std::vector<logging::filter::filter> no_filters {};
    std::unique_ptr<logging::logger::logger> const log = std::make_unique<logging::logger::simple_logger>(
        logging::level::trace,
        no_filters,
        std::make_unique<logging::handling::stdout_handler>(
            logging::level::trace,
            no_filters,
            std::make_unique<logging::format::simple_formatter>()
        )
    );

    log->trace("Created logger");

    log->debug("This is a debug logger");

    log->info("Hello world!");

    log->warn("About to quit!");

    log->error("An error!");

    return 0;
}
