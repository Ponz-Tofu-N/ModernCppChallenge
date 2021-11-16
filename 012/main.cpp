/*12. Collatz Numbers */
/*Usage: Enter the limit number up to 1,000,000.*/

#include <iostream>
#include "collatz.h"

int main(int argc, char const *argv[])
{
    int limit;
    std::cin >> limit;

    std::vector<std::pair<unsigned int, unsigned int>> collatzSizeLists;

    unsigned int root = 0;
    unsigned int size = 0;

    for (size_t i = 2; i < limit; i++)
    {
        int buf = Collatz::collatzSeqSize(i);
        if (buf > size)
        {
            root = i;
            size = buf;
        }
    }

    std::cout << "max root: " << root << "\n";
    std::cout << "max size: " << size << "\n";

    return 0;
}
