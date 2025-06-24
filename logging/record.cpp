#include "record.hpp"

logging::record::record(
    const logging::level level,
    const std::string_view message
) noexcept :
    message { message },
    time { std::time(nullptr) },
    level { level }
{}
