#pragma once

#include "handler.hpp"
#include "../filter/filter.hpp"
#include "../level.hpp"


namespace logging::handling {
    class file_handler final : public virtual handler {
        level handler_level;
        std::vector<filter::filter> filters;
        std::unique_ptr<format::formatter> formatter;
        std::FILE *file_out;

    public:
        // explicit file_handler(std::string const& file_path);
        file_handler(
            level handler_level,
            std::vector<filter::filter> filters,
            std::unique_ptr<format::formatter> formatter,
            std::string const& file_path
        );

        ~file_handler() override;

        void dispatch_record(record const& record) const noexcept override;
    };
}
