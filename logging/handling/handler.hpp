#pragma once
#include <vector>

#include "../filter/filter.hpp"
#include "../format/simple_formatter.hpp"


namespace logging::handling {
    struct handler {
        virtual ~handler() = default;
        virtual void dispatch_record(record record) const noexcept = 0;
    };

    [[nodiscard]] std::unique_ptr<handler> get_default_handler();
}
