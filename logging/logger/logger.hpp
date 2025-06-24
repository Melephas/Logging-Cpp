#pragma once

#include <memory>
#include <string_view>

#include "../record.hpp"


namespace logging::logger {
    struct logger {
        virtual ~logger() = default;

        virtual void handle_record(const record &record) const = 0;

        virtual void trace(std::string_view message) const = 0;
        virtual void debug(std::string_view message) const = 0;
        virtual void info(std::string_view message) const = 0;
        virtual void warn(std::string_view message) const = 0;
        virtual void error(std::string_view message) const = 0;
    };

    [[nodiscard]] std::unique_ptr<logger> get_default_logger();
}
