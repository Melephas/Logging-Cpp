#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "format/simple_formatter.hpp"
#include "record.hpp"
#include "level.hpp"

using Catch::Matchers::ContainsSubstring;
using logging::level;
using logging::record;
using logging::format::simple_formatter;

TEST_CASE("simple_formatter includes level abbreviation and message", "[formatter]") {
    const simple_formatter formatter;

    REQUIRE_THAT(formatter.format_record(record(level::trace, "hello")),
                 ContainsSubstring("TRC") && ContainsSubstring("hello"));
    REQUIRE_THAT(formatter.format_record(record(level::debug, "hello")),
                 ContainsSubstring("DBG") && ContainsSubstring("hello"));
    REQUIRE_THAT(formatter.format_record(record(level::information, "hello")),
                 ContainsSubstring("INF") && ContainsSubstring("hello"));
    REQUIRE_THAT(formatter.format_record(record(level::warning, "hello")),
                 ContainsSubstring("WRN") && ContainsSubstring("hello"));
    REQUIRE_THAT(formatter.format_record(record(level::error, "hello")),
                 ContainsSubstring("ERR") && ContainsSubstring("hello"));
}

TEST_CASE("simple_formatter preserves the record message verbatim", "[formatter]") {
    const simple_formatter formatter;
    const auto output = formatter.format_record(record(level::information, "unique-payload-42"));

    REQUIRE_THAT(output, ContainsSubstring("unique-payload-42"));
    // Structural separator between fields
    REQUIRE_THAT(output, ContainsSubstring(" | "));
}
