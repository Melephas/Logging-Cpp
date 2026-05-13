#pragma once

#include <stdexcept>
#include <string>


namespace logging::error {
    class factory_error final : public virtual std::runtime_error {
        std::string message;
    public:
        explicit factory_error(const char* message);
        explicit factory_error(const std::string& message);
        ~factory_error() override = default;

        [[nodiscard]] const char* what() const noexcept override;
        [[nodiscard]] std::string description() const noexcept;
    };
}
