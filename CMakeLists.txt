cmake_minimum_required(VERSION 3.31)
project(logging)

set(CMAKE_CXX_STANDARD 23)

add_executable(Logging main.cpp
    logging/level.hpp
    logging/level.cpp
    logging/record.hpp
    logging/record.cpp

    logging/format/formatter.hpp
    logging/format/formatter.cpp
    logging/format/simple_formatter.cpp
    logging/format/simple_formatter.hpp

    logging/error/conversion_error.hpp
    logging/error/conversion_error.cpp

    logging/filter/filter.hpp

    logging/handling/handler.cpp
    logging/handling/handler.hpp
    logging/handling/stdout_handler.cpp
    logging/handling/stdout_handler.hpp
    logging/logger/logger.cpp
    logging/logger/logger.hpp
    logging/logger/simple_logger.cpp
    logging/logger/simple_logger.hpp
)
