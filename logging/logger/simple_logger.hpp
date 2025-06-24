#pragma once

#include "logger.hpp"
#include "../handling/stdout_handler.hpp"


namespace logging::logger {
    class simple_logger final : virtual public logger {
        level level;
        std::vector<std::unique_ptr<filter::filter>> filters;
        std::vector<std::unique_ptr<handling::handler>> handlers;
    public:
        simple_logger();
        simple_logger(logging::level level, std::vector<std::unique_ptr<filter::filter>> filters, std::vector<std::unique_ptr<handling::handler>> handlers);
        ~simple_logger() override = default;

        void handle_record(const record &record) const override;

        void trace(std::string_view message) const override;
        void debug(std::string_view message) const override;
        void info(std::string_view message) const override;
        void warn(std::string_view message) const override;
        void error(std::string_view message) const override;
    };
}
