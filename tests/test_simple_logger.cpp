#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include <filesystem>
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "logger/simple_logger.hpp"
#include "handling/file_handler.hpp"
#include "format/simple_formatter.hpp"
#include "filter/filter.hpp"
#include "level.hpp"

using Catch::Matchers::ContainsSubstring;
using logging::level;
using logging::format::formatter;
using logging::format::simple_formatter;
using logging::handling::file_handler;
using logging::handling::handler;
using logging::logger::simple_logger;

namespace {
    std::filesystem::path logger_temp_path() {
        static int counter = 0;
        auto path = std::filesystem::temp_directory_path() /
            ("logging_logger_test_" + std::to_string(++counter) + ".log");
        std::filesystem::remove(path);
        return path;
    }

    std::string read_file(const std::filesystem::path& path) {
        std::ifstream in(path);
        std::stringstream buffer;
        buffer << in.rdbuf();
        return buffer.str();
    }

    std::unique_ptr<handler> make_file_handler(const std::filesystem::path& path) {
        return std::unique_ptr<handler>(std::make_unique<file_handler>(
            level::trace,
            std::vector<logging::filter::filter>{},
            std::unique_ptr<formatter>(std::make_unique<simple_formatter>()),
            path.string()
        ));
    }
}

TEST_CASE("simple_logger drops records below its level", "[logger]") {
    const auto path = logger_temp_path();

    {
        const simple_logger logger(level::warning, {}, make_file_handler(path));
        logger.info("info-below-level");
        logger.error("error-at-level");
    }

    const auto contents = read_file(path);
    REQUIRE_THAT(contents, ContainsSubstring("error-at-level"));
    REQUIRE_THAT(contents, !ContainsSubstring("info-below-level"));

    std::filesystem::remove(path);
}

TEST_CASE("simple_logger handles records at or above its level", "[logger]") {
    const auto path = logger_temp_path();

    {
        const simple_logger logger(level::trace, {}, make_file_handler(path));
        logger.trace("trace-msg");
        logger.debug("debug-msg");
        logger.info("info-msg");
        logger.warn("warn-msg");
        logger.error("error-msg");
    }

    const auto contents = read_file(path);
    REQUIRE_THAT(contents, ContainsSubstring("trace-msg"));
    REQUIRE_THAT(contents, ContainsSubstring("debug-msg"));
    REQUIRE_THAT(contents, ContainsSubstring("info-msg"));
    REQUIRE_THAT(contents, ContainsSubstring("warn-msg"));
    REQUIRE_THAT(contents, ContainsSubstring("error-msg"));

    std::filesystem::remove(path);
}

TEST_CASE("simple_logger applies filters to suppress records", "[logger]") {
    const auto path = logger_temp_path();

    {
        std::vector<logging::filter::filter> filters { logging::filter::one_line_max };
        const simple_logger logger(level::trace, filters, make_file_handler(path));
        logger.info(std::string(100, 'z'));
        logger.info("acceptable");
    }

    const auto contents = read_file(path);
    REQUIRE_THAT(contents, ContainsSubstring("acceptable"));
    REQUIRE_THAT(contents, !ContainsSubstring(std::string(100, 'z')));

    std::filesystem::remove(path);
}
