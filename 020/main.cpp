/* 20. any, all, none function for container class*/

#include <iostream>
#include "contrainerutil.h"
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 2, 3, 3};
    
    if(all(vec, 1, 2, 3, 3))
    {
        std::cout << "all match" << "\n";
    }
    else
    {
        std::cout << "not all match " << "\n";
    }

    
    return 0;
}
