#pragma once

#include <cstdio>
#include <string_view>

#include "handler.hpp"

#include "../level.hpp"


namespace logging::handling {
    class file_handler final : public virtual handler {
        level level;
        std::vector<filter::filter> filters;
        std::unique_ptr<format::formatter> formatter;
        std::FILE *file_out;
    public:
        explicit file_handler(const std::string& file_path);
        file_handler(
            logging::level level,
            std::vector<filter::filter> filters,
            std::unique_ptr<format::formatter> formatter,
            const std::string& file_path
        );

        ~file_handler() override;

        void dispatch_record(const record &record) const noexcept override;
    };
}
