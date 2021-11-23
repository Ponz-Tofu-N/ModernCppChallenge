#include "ipv4.h"
#include <iostream>

Ipv4::Ipv4()
:adress({0,0,0,0})
{
}

Ipv4::Ipv4(const std::uint8_t a,
           const std::uint8_t b,
           const std::uint8_t c,
           const std::uint8_t d)
            : adress({a, b, c, d})
{
    std::cout << "Initialized with uint8" << std::endl;
}

Ipv4::Ipv4(const Ipv4 & other)
{
    std::cout << "Copy-initailized" << std::endl;
    *this = other;
}

Ipv4::Ipv4(const std::string & input)
{
    std::string byte;
    for (auto itr = input.begin(); itr != input.cend(); ++itr)
    {
        if(*itr == '.')
        {
            adress.push_back(std::stoi(byte));
            byte.clear();
        }
        else
        {
            byte.push_back(*itr);
        }

        if(itr == input.end() - 1)
        {
            adress.push_back(std::stoi(byte));
        }
    }

    std::cout << "Initialized with string" << std::endl;
}
Ipv4::~Ipv4()
{
}

std::ostream& operator<<(std::ostream& os, const Ipv4& ip)
{
    for (auto itr = ip.adress.begin(); itr != ip.adress.cend(); ++itr)
    {
        os << static_cast<int>(*itr);
        if(itr != ip.adress.cend() - 1)
        {
            os << '.';
        }
    }

    return os;
}

std::istream& operator>>(std::istream& is, Ipv4& ip)
{
    char dot1, dot2, dot3;
    int byte1, byte2, byte3, byte4;

    const int check = 255;

    is >> byte1 >> dot1 >> byte2 >> dot2 >> byte3 >> dot3 >> byte4;

    if (dot1 == '.' && dot2 == '.' && dot3 == '.')
    {
        if (byte1 > 255U)
            byte1 &= check;
        if (byte2 > 255U)
            byte2 &= check;
        if (byte3 > 255U)
            byte3 &= check;
        if (byte4 > 255U)
            byte4 &= check;
        
        ip = Ipv4(byte1, byte2, byte3, byte4);
    }
    else
    {
        /* 文字列が不正の場合は、std::ios_base::iostateでstd::ios_base::failbitを設定する。 */
        is.setstate(std::ios_base::failbit);
    }
    
    return is;
}

Ipv4& Ipv4::operator=(const Ipv4& other)
{
    adress = other.adress;
    return *this;
}

Ipv4& Ipv4::operator++()
{
    unsigned long ip_ulong = 0;

    ip_ulong = (adress[0] << 24) | 
               (adress[1] << 16) |
               (adress[2] << 8) |
               adress[3];
    
    ip_ulong++;

    adress[0] = static_cast<uint8_t>(ip_ulong >> 24);
    adress[1] = static_cast<uint8_t>(ip_ulong >> 16);
    adress[2] = static_cast<uint8_t>(ip_ulong >> 8);
    adress[3] = static_cast<uint8_t>(ip_ulong);
    
    return *this;
}

/*comparison operator*/
bool operator<(const Ipv4& fst, const Ipv4& scd)
{
    for (size_t i = 0 ; i < 4; i++)
    {
        if (fst.adress[i] < scd.adress[i])
        {
            return true;
        }
    }

    return false;
}

bool operator==(const Ipv4& fst, const Ipv4& scd)
{
    for (size_t i = 0 ; i < 4; i++)
    {
        if (fst.adress[i] != scd.adress[i])
        {
            return false;
        }
    }

    return true; 
}