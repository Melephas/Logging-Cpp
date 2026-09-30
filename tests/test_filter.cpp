#include <catch2/catch_test_macros.hpp>

#include <string>

#include "filter/filter.hpp"
#include "record.hpp"
#include "level.hpp"

using logging::level;
using logging::record;

namespace {
    record make(const std::string& message) {
        return record(level::information, message);
    }
}

TEST_CASE("all filter returns false, none filter returns true", "[filter]") {
    REQUIRE_FALSE(logging::filter::all(make("anything")));
    REQUIRE(logging::filter::none(make("anything")));
}

TEST_CASE("no_emails matches email-containing messages", "[filter]") {
    REQUIRE(logging::filter::no_emails(make("contact john@example-org.com now")));
    REQUIRE(logging::filter::no_emails(make("jane.doe@my-mail.co")));
}

TEST_CASE("no_emails rejects near-email strings", "[filter]") {
    REQUIRE_FALSE(logging::filter::no_emails(make("no address here")));
    REQUIRE_FALSE(logging::filter::no_emails(make("just some text without at sign")));
}

TEST_CASE("one_line_max triggers only above 80 characters", "[filter]") {
    const std::string len80(80, 'x');
    const std::string len81(81, 'x');
    const std::string len40(40, 'x');

    REQUIRE_FALSE(logging::filter::one_line_max(make(len40)));
    REQUIRE_FALSE(logging::filter::one_line_max(make(len80)));
    REQUIRE(logging::filter::one_line_max(make(len81)));
}
