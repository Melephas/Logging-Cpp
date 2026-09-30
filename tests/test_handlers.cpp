#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include <filesystem>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>

#include "handling/file_handler.hpp"
#include "format/simple_formatter.hpp"
#include "filter/filter.hpp"
#include "record.hpp"
#include "level.hpp"

using Catch::Matchers::ContainsSubstring;
using logging::level;
using logging::record;
using logging::format::formatter;
using logging::format::simple_formatter;
using logging::handling::file_handler;

namespace {
    std::filesystem::path unique_temp_path() {
        static int counter = 0;
        auto path = std::filesystem::temp_directory_path() /
            ("logging_test_" + std::to_string(++counter) + ".log");
        std::filesystem::remove(path);
        return path;
    }

    std::string read_file(const std::filesystem::path& path) {
        std::ifstream in(path);
        std::stringstream buffer;
        buffer << in.rdbuf();
        return buffer.str();
    }
}

TEST_CASE("file_handler writes formatted records to a file", "[handler][file]") {
    const auto path = unique_temp_path();

    {
        file_handler handler(
            level::trace,
            {},
            std::unique_ptr<formatter>(std::make_unique<simple_formatter>()),
            path.string()
        );
        handler.dispatch_record(record(level::information, "file-message-abc"));
    } // handler destroyed -> file flushed and closed

    const auto contents = read_file(path);
    REQUIRE_THAT(contents, ContainsSubstring("INF"));
    REQUIRE_THAT(contents, ContainsSubstring("file-message-abc"));

    std::filesystem::remove(path);
}

TEST_CASE("file_handler drops records below its level", "[handler][file]") {
    const auto path = unique_temp_path();

    {
        file_handler handler(
            level::warning,
            {},
            std::unique_ptr<formatter>(std::make_unique<simple_formatter>()),
            path.string()
        );
        handler.dispatch_record(record(level::debug, "should-not-appear"));
        handler.dispatch_record(record(level::error, "should-appear"));
    }

    const auto contents = read_file(path);
    REQUIRE_THAT(contents, ContainsSubstring("should-appear"));
    REQUIRE_THAT(contents, !ContainsSubstring("should-not-appear"));

    std::filesystem::remove(path);
}

TEST_CASE("file_handler suppresses records rejected by a filter", "[handler][file]") {
    const auto path = unique_temp_path();

    {
        std::vector<logging::filter::filter> filters { logging::filter::one_line_max };
        file_handler handler(
            level::trace,
            filters,
            std::unique_ptr<formatter>(std::make_unique<simple_formatter>()),
            path.string()
        );
        handler.dispatch_record(record(level::information, std::string(90, 'y')));
        handler.dispatch_record(record(level::information, "short-line"));
    }

    const auto contents = read_file(path);
    REQUIRE_THAT(contents, ContainsSubstring("short-line"));
    REQUIRE_THAT(contents, !ContainsSubstring(std::string(90, 'y')));

    std::filesystem::remove(path);
}
