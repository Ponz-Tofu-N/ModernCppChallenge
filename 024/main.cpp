/* 24. Conversion from String to Binary*/

/*
 * Features:
 * - Return array or vector containing 8 bits integers from the given Hex style string.
 * - Upper case and lower case are allowed to use.
 * - input: "BAADF00D" or "baadf00d" -> output: {0xBA, 0xAD, 0xF0, 0x0D}
 * - input: "010203040506"           -> output: {1, 2, 3, 4, 5, 6}
 */

#include <array>
#include <iostream>
#include <vector>

#include "hexutils.h"

int main(int argc, char const *argv[])
{
    auto bytes = hex::strToHex(std::string("BAADF00D"));
    std::vector<uint8_t> arr = {0xBA, 0xAD, 0xF0, 0x0D};
    if (arr == bytes)
        std::cout << "match" << std::endl;
    else
        std::cout << "not match" << std::endl;

    return 0;
}
