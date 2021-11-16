#ifndef ROMAN_H
#define ROMAN_H

#include <array>
#include <algorithm>

const std::array<std::pair<unsigned int, std::string>, 13> romanMap 
{
    std::make_pair(1, "I"),
    std::make_pair(4, "IV"),
    std::make_pair(5, "V"),
    std::make_pair(9, "IX"),
    std::make_pair(10, "X"),
    std::make_pair(40, "XL"),
    std::make_pair(50, "L"),
    std::make_pair(90, "XC"),
    std::make_pair(100, "C"),
    std::make_pair(400, "CD"),
    std::make_pair(500, "D"),
    std::make_pair(900, "CM"),
    std::make_pair(1000, "M")
};

const std::string makeRoman(unsigned int target)
{
    std::string result;
    while (target > 0)
    {
        auto root = std::find_if(romanMap.begin(), romanMap.end(), [&](std::pair<unsigned int, std::string> pair)
        {
            return pair.first >= target;
        });

        if(root->first == target)
        {
            result += root->second;
            break;
        }
        else
        {
            result += (root - 1)->second;
            target -= (root - 1)->first;
        }
    }

    return result;
}

#endif