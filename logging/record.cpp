#include "record.hpp"

logging::record::record(const level record_level, const std::string_view message) noexcept
    : message { message }, time { std::chrono::system_clock::now() }, record_level { record_level } {}
