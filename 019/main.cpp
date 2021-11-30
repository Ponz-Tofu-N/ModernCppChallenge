/* 19. Push back with variadic arguments to container*/

#include <iostream>
#include "./variadic.h"

int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    push_back_variadic(vec, 1, 2, 3, 4, 5, 6, 7);

    std::cout << "values: " ;
    for (auto && value:vec)
    {
        std::cout << value << " ";
    }
    
    return 0;
}
