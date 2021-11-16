/*12. Collatz Numbers */
/*Usage: Enter the limit number up to 1,000,000.*/

#include <iostream>
#include "collatz.h"

int main(int argc, char const *argv[])
{
    int limit;
    std::cin >> limit;

    auto largestpair = Collatz::largestPair(limit);

    std::cout << "max size: " << largestpair.first << "\n";
    std::cout << "max root: " << largestpair.second << "\n";

    return 0;
}
