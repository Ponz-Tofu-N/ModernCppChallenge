/*11. Arabic to Roman */
/*Usage: Enter the target number up to 1000.*/

#include <iostream>
#include "roman.h"

int main(int argc, char const *argv[])
{
    int target; std::cin >> target;
    std::cout << target << ": " ;

    std::cout << makeRoman(target) << "\n";

    return 0;
}

