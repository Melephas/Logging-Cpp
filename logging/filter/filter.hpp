#pragma once

#include <functional>
#include <regex>

#include "../record.hpp"


namespace logging::filter {
    typedef std::function<bool(const record &record)> filter;

    inline filter all = [](const record &_){ return false; };

    inline filter none = [](const record &_){ return true; };

    inline filter no_emails = [](const record &record){
        const std::regex email_regex(R"([\w\-\.]+@([\w\-]+\-)+[\w]{2,})");
        return std::regex_search(record.message, email_regex);
    };

    inline filter one_line_max = [](const record &record) {
        return record.message.length() > 80;
    };
}
