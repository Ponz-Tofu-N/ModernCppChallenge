/* 15. IPv4 Data Type */
/* Usage: Enter 10 digit number. */

#include <iostream>
#include "ipv4.h"

int main(int argc, char const *argv[])
{

    /*Initialized with uint8*/
    Ipv4 uint8_ipv4(127, 120, 45, 0);
    std::cout << "uint8: " << uint8_ipv4 << std::endl;
    
    /*Initialized with string*/
    Ipv4 str_ipv4("255.255.255.255");
    std::cout << "string: " << str_ipv4 << std::endl;

    /* Copied Ipv4*/
    Ipv4 copy_ipv4 = uint8_ipv4;
    std::cout << "copied: " << copy_ipv4 << std::endl;

    /* Initialized with user input */
    Ipv4 cin_inp4;
    std::cin >> cin_inp4;
    if (std::cin.fail())
    {
        std::cout << "invalid input." << std::endl;
    }
    else
    {
        std::cout << "Standard Input: " << cin_inp4 << std::endl;
    }
    
    return 0;
}

