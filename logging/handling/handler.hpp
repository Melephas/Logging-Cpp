#pragma once

#include "../format/simple_formatter.hpp"


namespace logging::handling {
    struct handler {
        virtual ~handler() = default;

        // Handle the given record
        virtual void dispatch_record(record const& record) const noexcept = 0;
    };
}
