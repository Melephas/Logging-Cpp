#include "record.hpp"

logging::record::record(const level record_level, const std::string_view message) noexcept
    : message { message }, time { time::now() }, record_level { record_level } {}
