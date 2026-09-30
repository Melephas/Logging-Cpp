#include <catch2/catch_test_macros.hpp>

TEST_CASE("test toolchain builds and runs", "[smoke]") {
    REQUIRE(1 + 1 == 2);
}
