//4. Max Prime Number less than the given number
// Usage: Enter a number.

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
    Util::ui num; std::cin >> num;
    for (Util::ui i = num; i >= 0; i--)
    {
        if(isPrime(i))
        {
            std::cout << "Max Prime is " << i << "\n";
            break;
        }
    }
    return 0;
}
