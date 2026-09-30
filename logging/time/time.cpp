#include "time.hpp"

#include <stdexcept>

#include "chrono_time.hpp"
#include "c_time.hpp"

#ifdef NO_STD_CHRONO
std::unique_ptr<logging::time::time> logging::time::now() {
    return std::make_unique<c_time>();
}

#elifndef NO_STD_CHRONO
std::unique_ptr<logging::time::time> logging::time::now() {
    return std::make_unique<chrono_time>();
}

#endif
