// 3. LCM of two or more positive integers
// Usage: 1. Enter the number of inputs.
// Usage: 2. Enter as many times as above.

#include <iostream>
#include "ponz_utility.h"

int main(int argc, char const *argv[])
{
    Util::ui n, res, element;

    std::cin >> n >> res;
    for (size_t i = 1; i < n; i++)
    {
        std::cin >> element;
        res = Util::lcm(res, element);
    }
    std::cout << res << "\n";

    return 0;
}
