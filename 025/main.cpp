/* 25. Capitalization */

/*
 * Features:
 * - Capitalize the given text.
 * - "the c++ challenger" -> "The C++ Challenger"
 */

#include <array>
#include <iostream>
#include <vector>

#include "capitalize.h"

int main(int argc, char const *argv[])
{
    std::string str = capitalize("the c++ challenger");

    std::cout << str << "\n";
    return 0;
}
