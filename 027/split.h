#include <string>
#include <sstream>
#include <iterator>

template <class C>
C split(const std::string &input, char delimiter)
{
    C tokens;
    std::istringstream iss(input);
    std::string token;

    while(std::getline(iss, token, ' '))
    {
        tokens.push_back(token);
    }

    return tokens;
}

template <class C>
C split(const std::string &input, const std::string &delimiters)
{
    C tokens;
    std::string token;
    std::istringstream iss(input);
    size_t pos, prev_pos = 0;

    while ((pos = input.find_first_of(delimiters, prev_pos)) != std::string::npos)
    {
        std::getline(iss, token, input[pos]);
        tokens.push_back(token);
        prev_pos = ++pos;
    }

    tokens.push_back(input.substr(prev_pos));

    return tokens;
}