/*13. Calculate PI with Monte Carlo Method*/
/*Usage: Enter number of coocoordinates.*/

#include <iostream>
#include "pi.h"

int main(int argc, char const *argv[])
{
    std::cout << "Enter number of coocoordinates: ";
    unsigned int coordinates; std::cin >> coordinates;

    std::cout << "PI: " << PI::calcPI(coordinates) << "\n";

    return 0;
}
