#pragma once

#include <string_view>

#include "../filter/filter.hpp"
#include "../format/simple_formatter.hpp"


namespace logging::handling {
    struct handler {
        virtual ~handler() = default;

        // Handle the given record
        virtual void dispatch_record(const record &record) const noexcept = 0;
    };

    [[nodiscard]] std::unique_ptr<handler> get_handler(std::string_view target);
}
