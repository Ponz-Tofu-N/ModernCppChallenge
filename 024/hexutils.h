#include <array>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

namespace hex
{
    enum class CASE {Upper, Lower};
    static constexpr uint8_t toHex(const std::uint16_t n, CASE mode = CASE::Upper)
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
    static constexpr std::string hexToStr(const T &arr, CASE mode = CASE::Upper)
    {
        std::string ret;
        for (auto &&n : arr)
        {
            ret.push_back(toHex(n >> 4, mode));
            ret.push_back(toHex(n & 15, mode));
        }

        return ret;
    }

    template <class T>
    static constexpr std::string bToStr(const T &arr, CASE mode = CASE::Upper)
    {
        std::ostringstream oss;
        oss << std::hex;
        
        switch (mode)
        {
        case CASE::Upper:
            oss << std::uppercase;
            break;
        case CASE::Lower:
            oss << std::nouppercase;
            break;
        default:
            break;
        }

        for (auto &&byte : arr){
            oss.width(2);
            oss.fill('0');
            oss << static_cast<int>(byte);
        }

        return oss.str();
    }

    uint8_t charToBin(const char c)
    {
        if ( '0' <= c && c <= '9') return c - '0';
        if ( 'A' <= c && c <= 'F') return c - 'A' + 10;
        if ( 'a' <= c && c <= 'f') return c - 'a' + 10;

        throw std::invalid_argument(&c);
    }

    static std::vector<uint8_t> strToHex(const std::string& str)
    {
        const int cap = str.size() / 2;
        std::vector<uint8_t> ret;

        ret.reserve(cap);

        for (auto itr = str.begin(); itr != str.end(); itr += 2)
        {
            auto fst = charToBin(*itr);
            auto scd = charToBin(*(itr + 1));

            uint8_t byte = (fst << 4) | scd;

            ret.push_back(byte);
        }

        return ret;
    }

    static std::vector<uint8_t> strToHex(const char* str)
    {
        std::string buf(str);
        return strToHex(buf);
    }
}