#pragma once
#include "handler.hpp"

namespace logging::handling {
    class stdout_handler final : virtual public handler {
        level level;
        std::vector<filter::filter> filters;
        std::unique_ptr<format::formatter> formatter;
    public:
        stdout_handler();
        stdout_handler(logging::level level, std::vector<filter::filter> filters, std::unique_ptr<format::formatter> formatter);
        ~stdout_handler() override = default;

        // Outputs the formatted record to stdout if it passes all the filters
        void dispatch_record(const record &record) const noexcept override;
    };
}
