#include <array>
#include <iostream>

namespace hex
{
    enum class CASE {Upper, Lower};
    static uint8_t toHex(const std::uint16_t n, CASE mode = CASE::Upper)
    {
        std::uint8_t root = 'A';
        if(mode == CASE::Upper) root = 'A';
        if(mode == CASE::Lower) root = 'a';

        if (0 <= n && n < 10)
        {
            return n + '0';
        }
        else if(10 <= n && n < 16)
        {
            return n + root - 10;
        }
        return '\0';
    }

    template <class T>
    static std::string hexToStr(const T &arr, CASE mode = CASE::Upper)
    {
        std::string ret;
        for (auto &&n : arr)        
        {
            ret.push_back(toHex(n >> 4, mode));
            ret.push_back(toHex(n & 15, mode));
        }

        return ret;
    }
}