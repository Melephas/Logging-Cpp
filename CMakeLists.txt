cmake_minimum_required(VERSION 3.31)
project(logging)

set(CMAKE_CXX_STANDARD 23)

add_library(Logging
    logging/level.hpp
    logging/level.cpp
    logging/record.hpp
    logging/record.cpp

    logging/format/formatter.hpp
    logging/format/simple_formatter.cpp
    logging/format/simple_formatter.hpp

    logging/error/conversion_error.hpp
    logging/error/conversion_error.cpp

    logging/filter/filter.hpp

    logging/handling/handler.hpp
    logging/handling/stdout_handler.cpp
    logging/handling/stdout_handler.hpp
    logging/logger/logger.hpp
    logging/logger/simple_logger.cpp
    logging/logger/simple_logger.hpp
    logging/handling/file_handler.cpp
    logging/handling/file_handler.hpp
    logging/logging.hpp
    logging/time/time.cpp
    logging/time/time.hpp
    logging/time/chrono_time.cpp
    logging/time/chrono_time.hpp
    logging/time/c_time.cpp
    logging/time/c_time.hpp
)

target_include_directories(Logging PUBLIC logging)

option(NO_STD_CHRONO "Use the C time library (for when C++ std::chrono is incomplete)" ON)
if (NO_STD_CHRONO)
    target_compile_definitions(
        Logging PRIVATE
            NO_STD_CHRONO
    )
endif ()

option(BUILD_LOGGING_TESTS "Build the Logging unit tests" ${PROJECT_IS_TOP_LEVEL})
if (BUILD_LOGGING_TESTS)
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.6.0
    )
    FetchContent_MakeAvailable(Catch2)

    enable_testing()
    add_subdirectory(tests)
endif ()
