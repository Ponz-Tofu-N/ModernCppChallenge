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
    std::string input;
    is >> input; 
    ip = Ipv4(input);
    return is;
}