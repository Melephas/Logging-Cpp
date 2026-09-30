#include <catch2/catch_test_macros.hpp>

#include <string>

#include "error/conversion_error.hpp"

using logging::error::conversion_error;

TEST_CASE("conversion_error from c-string exposes message", "[conversion_error]") {
    const conversion_error err("bad conversion");

    REQUIRE(std::string(err.what()) == "bad conversion");
    REQUIRE(err.description() == "bad conversion");
}

TEST_CASE("conversion_error from std::string exposes message", "[conversion_error]") {
    const std::string message = "invalid level value";
    const conversion_error err(message);

    REQUIRE(std::string(err.what()) == message);
    REQUIRE(err.description() == message);
}
