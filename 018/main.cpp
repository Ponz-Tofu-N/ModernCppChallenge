/* 18. variadic arguments */

#include <iostream>
#include "./variadic.h"

int main(int argc, char const *argv[])
{
    std::cout << "2,3,4,1,5,6" << std::endl;
    std::cout << "min: " << minimum(2,3,4,1,5,6) << std::endl;
    return 0;
}

