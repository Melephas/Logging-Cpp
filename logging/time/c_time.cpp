#include "c_time.hpp"

#include <stdexcept>

std::string logging::time::c_time::format() const {
    char timeString[std::size("yyyy-mm-ddThh:mm:ssZ")];
    std::strftime(std::data(timeString), std::size(timeString), "%FT%TZ", std::gmtime(&time_point));
    return std::string { timeString };
}
