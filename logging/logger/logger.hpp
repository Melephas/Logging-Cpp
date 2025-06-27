#pragma once

#include <memory>
#include <string_view>

#include "../record.hpp"

#include "../handling/handler.hpp"


namespace logging::logger {
    struct logger {
        virtual ~logger() = default;

        // Handle the logging of an already generated log record
        virtual void handle_record(const record &record) const = 0;

        // Log a `trace` message
        virtual void trace(std::string_view message) const = 0;
        // Log a `debug` message
        virtual void debug(std::string_view message) const = 0;
        // Log a `info` message
        virtual void info(std::string_view message) const = 0;
        // Log a `warn` message
        virtual void warn(std::string_view message) const = 0;
        // Log a `error` message
        virtual void error(std::string_view message) const = 0;
    };

    [[nodiscard]] std::unique_ptr<logger> get_logger();
    [[nodiscard]] std::unique_ptr<logger> get_logger(std::string_view target);
}
