#pragma once
#include <ctime>

#include "time.hpp"

namespace logging::time {
    class c_time : public time {
        std::time_t time_point = std::time(nullptr);
    public:
        ~c_time() override;
        [[nodiscard]] std::string format() const override;
    };
}
