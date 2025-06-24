#pragma once

#include "../record.hpp"


namespace logging::filter {
    struct filter {
        filter() noexcept = default;
        virtual ~filter() noexcept = default;

        [[nodiscard]] virtual bool should_drop(const record& record) const noexcept = 0;
    };
}
