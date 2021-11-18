/*13. Calculate PI with Monte Carlo Method*/
/*Usage: Enter number of coocoordinates.*/

#include <iostream>
#include "pi.h"

int main(int argc, char const *argv[])
{
    std::cout << "Enter number of samples: ";
    unsigned int coordinates; std::cin >> coordinates;

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << i << " .PI: " << PI::calcPI(coordinates) << "\n";
    }
    

    return 0;
}
