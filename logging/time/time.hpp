#pragma once
#include <memory>
#include <string>

namespace logging::time {
    class time {
    public:
        virtual ~time() = default;
        [[nodiscard]] virtual std::string format() const = 0;
    };

    std::unique_ptr<time> now();
}
