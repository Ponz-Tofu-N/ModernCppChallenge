/* 16. IPv4 Data Type */
/* Usage: Enter ipv4 adress. */

#include <iostream>
#include "ipv4.h"

int main(int argc, char const *argv[])
{

    Ipv4 first, second, middle;
    std::cin >> first >> second;

    std::cout << "first: " << first << std::endl;
    std::cout << "second: " << second << std::endl;

    middle = first;
    while (first < second)
    {
        std::cout << middle << std::endl;
        middle++;
    }
    
    return 0;
}

