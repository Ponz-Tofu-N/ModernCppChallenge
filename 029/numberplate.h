#include <string>
#include <regex>

bool validate(const std::string &input, const std::string &str_re)
{
    std::regex expected_re(str_re);
    return std::regex_match(input, expected_re);
}

std::vector<std::string> find_numberplate(const std::string &input, const std::string &str_re)
{
    std::smatch matches;
    std::vector<std::string> result;
    std::regex re(str_re);

    for(auto it = std::sregex_iterator(std::begin(input), std::end(input), re); it != std::sregex_iterator(); ++it)
    {
        auto smatch = *it;
        auto size = smatch.size();
        auto sub_match = smatch[size-1];
        
        if (sub_match.matched)
            result.push_back(sub_match.str());
    }

    return result;
}
