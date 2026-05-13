#pragma once

#include "logger/simple_logger.hpp"


namespace logging {
    class factory {
        using logger_interface = logger::logger;
        using logger_type = logger::simple_logger;

        using handler_interface = handling::handler;
        using handler_type = handling::stdout_handler;

        using formatter_interface = format::formatter;
        using formatter_type = format::simple_formatter;

        filter::filter filter_type = filter::all;

    public:
        static std::unique_ptr<logger_interface> get_logger(std::string_view hints);
        static std::unique_ptr<handler_interface> get_handler(std::string_view hints, level handler_level = level::debug);
        static std::unique_ptr<formatter_interface> get_formatter(std::string_view hints);
    };
}
