/* 35. directory size */

/*
 * Features:
 * Print directory size
 */

#include "directory.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string path{"./test/test"};

    list_directory(path);
    std::cout << "size: " << directory_size(path) << std::endl;

    return 0;
}

