/* 28. Longest palindrome */

/*
 * Features:
 * - "optharararahing" -> "harararah"
 */

#include <iostream>

#include "palindrome.h"

int main()
{
    std::string input{"optharararahingararararararararara"};
    // std::string input2{"this,is an!example"};

    std::cout << find_palindrome(input) << "\n";

    return 0;

}
