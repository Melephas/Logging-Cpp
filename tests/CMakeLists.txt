add_executable(LoggingTests
    test_smoke.cpp
    test_level.cpp
    test_record.cpp
    test_conversion_error.cpp
    test_simple_formatter.cpp
    test_filter.cpp
    test_handlers.cpp
    test_simple_logger.cpp
)

target_link_libraries(LoggingTests PRIVATE Logging Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(Catch)
catch_discover_tests(LoggingTests)
