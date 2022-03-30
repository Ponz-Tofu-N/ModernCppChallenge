/* 29. Validate Number Plate */

/*
 * Features:
 * validate if a number plate matches the following pattern.
 * - LLL-LL DDD
 * - LLL-LL DDDD
 */

#include <iostream>
#include <vector>

#include "numberplate.h"

int main()
{
    std::string re(R"(([A-Z]{3}-[A-Z]{2} \d{3,4})*)");
    std::string input("ABC-AB 1000 QJ ABC-ABC 1000 QJDSKJFGABC-AB 100 abc-AB 100");
    std::vector<std::string> exp_str;

    exp_str.push_back("ABC-AB 1000");
    exp_str.push_back("ABC-AB 100");

    auto results = find_numberplate(input, re);

    for (auto && str: exp_str)
    {
        std::cout << str << "\n";
    }
    for (auto && result: results)
    {
        std::cout << result << "\n";
    }
    

    return 0;

}
