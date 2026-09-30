#pragma once
#include <chrono>
#include <string>
#include "time.hpp"

namespace logging::time {
    class chrono_time : public time {
        std::chrono::time_point<std::chrono::system_clock> time_point = std::chrono::system_clock::now();
    public:
        ~chrono_time() override = default;

        [[nodiscard]] std::string format() const override;
    };
}
