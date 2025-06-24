#pragma once

#include <stdexcept>
#include <string>

namespace logging::error {
    class conversion_error final : public virtual std::runtime_error {
        std::string message;
    public:
        explicit conversion_error(const char* message);
        explicit conversion_error(const std::string& message);
        ~conversion_error() override = default;

        [[nodiscard]] const char* what() const noexcept override;
        [[nodiscard]] std::string description() const noexcept;
    };
}
