// 5. Sexy Prime Number
// Usage: Enter 1 number.

#include <iostream>
#include <cmath>
#include <string>

#include "ponz_utility.h"

bool isPrime(const Util::ui& num)
{
    if(num < 3)
    {
        return num > 1;
    }

    for (Util::ui i = 2; i < num; i++)
    {
        if (!(num % i))
        {
            return false;
        }

        if(i > sqrt(num))
            return true;
    }
    return true;    
}

int main(int argc, char const *argv[])
{
    std::cout << "input number: ";
    Util::ui num; std::cin >> num;
    for (Util::ui i = num; i >= 0; i--)
    {
        if(isPrime(i))
        {
            std::cout << "Max Prime is " << i << "\n";
            return 0;
        }
    }
    return 0;
}
