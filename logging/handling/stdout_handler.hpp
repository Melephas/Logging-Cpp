#pragma once
#include "handler.hpp"
#include "../filter/filter.hpp"

namespace logging::handling {
    class stdout_handler final : virtual public handler {
        level handler_level;
        std::vector<filter::filter> filters;
        std::unique_ptr<format::formatter> formatter;
    public:
        // stdout_handler();
        stdout_handler(level handler_level, std::vector<filter::filter> filters, std::unique_ptr<format::formatter> formatter);
        ~stdout_handler() override = default;

        // Outputs the formatted record to stdout if it passes all the filters
        void dispatch_record(record const& record) const noexcept override;
    };
}
