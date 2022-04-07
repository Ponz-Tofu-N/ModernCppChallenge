#include <regex>
#include <iostream>
#include <optional>

namespace rx{
    std::string parseDate(const std::string& text, const std::string& str_re)
    {
        auto re = std::regex(str_re);
        return std::regex_replace(text.c_str(), re, "$5-$3-$1");
    }
}