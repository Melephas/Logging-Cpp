#pragma once

#include <memory>
#include <string_view>

#include "../record.hpp"

namespace logging::format {
    struct formatter {
        formatter() noexcept = default;
        virtual ~formatter() noexcept = default;

        [[nodiscard]] virtual std::string format_record(const record& record) const noexcept = 0;
    };

    [[nodiscard]] std::unique_ptr<formatter> get_default_formatter() noexcept;
}
