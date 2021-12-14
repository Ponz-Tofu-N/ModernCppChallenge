/* 23. Conversion from Binary to String*/

/*
 * Features:
 * - Return Hex style string from the given array or vector containing 8 bits integers.
 * - Upper case and lower case are allowed to use.
 * - input: {0xBA, 0xAD, 0xF0, 0x0D} -> output: "BAADF00D" or "baadf00d"
 * - input: {1, 2, 3, 4, 5, 6}       -> output: "010203040506"
 */

#include <array>
#include <iostream>

#include "hexutils.h"

int main(int argc, char const *argv[])
{
    std::array<uint8_t, 4> input = {0xBA, 0xAD, 0xF0, 0x0D};
    std::array<uint8_t, 6> input2 = {1, 2, 3, 4, 5, 6};

    std::cout << hex::hexToStr(input) << std::endl;
    std::cout << hex::hexToStr(input, hex::CASE::Lower) << std::endl;

    std::cout << hex::hexToStr(input2) << std::endl;
    std::cout << hex::hexToStr(input2, hex::CASE::Lower) << std::endl;

    std::cout << hex::bToStr(input) << std::endl;
    std::cout << hex::bToStr(input, hex::CASE::Lower) << std::endl;

    return 0;
}
