/* 18. variadic arguments */

#include <iostream>
#include <functional>
#include "./variadic.h"

int main(int argc, char const *argv[])
{
    std::cout << "2,3,4,1,5,6" << std::endl;
    std::cout << "min: " << minimum(2, 3, 4, 1, 5, 6) << std::endl;

    auto res_min = functionalCompare(std::less<>(), 5, 6, 2, 7);
    std::cout << "min with func: " << res_min << std::endl;

    auto res_max = functionalCompare(std::greater<>(), 5, 6, 2, 7);
    std::cout << "max with func: " << res_max << std::endl;
    return 0;
}

