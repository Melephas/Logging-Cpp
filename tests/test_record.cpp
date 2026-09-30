#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include <string>

#include "record.hpp"
#include "level.hpp"

using Catch::Matchers::ContainsSubstring;
using logging::level;
using logging::record;

TEST_CASE("record stores message and level", "[record]") {
    const record r(level::warning, "something happened");

    REQUIRE(r.message == "something happened");
    REQUIRE(r.record_level == level::warning);
}

TEST_CASE("record sets a plausible construction time", "[record]") {
    const record r(level::information, "timed");

    // The time is now an abstract time object exposing a formatted string
    // (backed by std::chrono or the C time library depending on NO_STD_CHRONO).
    const auto formatted = r.time->format();

    REQUIRE_FALSE(formatted.empty());
    // ISO-8601-style timestamp: date and time separated by 'T'
    REQUIRE_THAT(formatted, ContainsSubstring("T"));
    REQUIRE_THAT(formatted, ContainsSubstring(":"));
    REQUIRE_THAT(formatted, ContainsSubstring("-"));
}
