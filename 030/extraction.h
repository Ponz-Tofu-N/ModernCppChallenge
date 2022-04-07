#include <regex>
#include <iostream>
#include <optional>

namespace rx{
    struct urlparts
    {
        std::string protcol;
        std::string domain;

        std::optional<int> port;
        std::optional<std::string> path;
        std::optional<std::string> query;
        std::optional<std::string> fragment;
    };

    std::optional<urlparts> parse_url(const std::string &input, const std::string &str_re)
    {
        std::regex re(str_re);
        std::smatch matches;
        urlparts url;

        if(std::regex_match(input, matches, re))
        {
            if (matches[1].matched && matches[2].matched)
            {
                url.protcol = matches[1].str();
                url.domain = matches[2].str();
            }
            
            if (matches[3].matched)
                url.port = std::stoi(matches[3].str());
            
            if (matches[4].matched)
                url.path = matches[4].str();
            
            if (matches[5].matched)
                url.query = matches[5].str();
            
            if (matches[6].matched)
                url.fragment = matches[6].str();
        }

        return url;
    }
}