#include <catch2/catch_test_macros.hpp>

#include "level.hpp"
#include "error/conversion_error.hpp"

using logging::level;

TEST_CASE("level_allows_level gates by severity", "[level]") {
    // A base level allows records of equal or higher severity
    REQUIRE(logging::level_allows_level(level::trace, level::trace));
    REQUIRE(logging::level_allows_level(level::trace, level::error));
    REQUIRE(logging::level_allows_level(level::information, level::information));
    REQUIRE(logging::level_allows_level(level::information, level::error));

    // A base level rejects records of lower severity
    REQUIRE_FALSE(logging::level_allows_level(level::error, level::trace));
    REQUIRE_FALSE(logging::level_allows_level(level::warning, level::information));
    REQUIRE_FALSE(logging::level_allows_level(level::information, level::debug));
}

TEST_CASE("level_to_string returns text for every valid level", "[level]") {
    REQUIRE(logging::level_to_string(level::trace) == "trace");
    REQUIRE(logging::level_to_string(level::debug) == "debug");
    REQUIRE(logging::level_to_string(level::information) == "information");
    REQUIRE(logging::level_to_string(level::warning) == "warning");
    REQUIRE(logging::level_to_string(level::error) == "error");
}

TEST_CASE("level_to_string throws on invalid value", "[level]") {
    REQUIRE_THROWS_AS(logging::level_to_string(static_cast<level>(99)),
                      logging::error::conversion_error);
}
