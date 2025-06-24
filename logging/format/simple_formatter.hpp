#pragma once

#include <map>
#include <string>

#include "formatter.hpp"


namespace logging::format {
    struct simple_formatter final : virtual formatter {
        simple_formatter() noexcept;
        ~simple_formatter() override = default;

        [[nodiscard]] std::string format_record(const record& record) const noexcept override;

    private:
        // 'Constants'
        std::map<level, std::string> level_format_table;
        std::string time_format_string;

        [[nodiscard]] std::string format_level(const level& level) const;
        [[nodiscard]] std::string format_time(const std::time_t& time) const;

    };
}
