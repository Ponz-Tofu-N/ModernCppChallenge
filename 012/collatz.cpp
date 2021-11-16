#include "collatz.h"

namespace Collatz
{
    /* create the size of Collatz sequence with root num */
    unsigned int collatzSeqSize(const unsigned int &root)
    {
        int size = 0;
        unsigned int buf = root;

        while (1 != buf)
        {
            if (buf % 2 == 0)
            {
                buf = buf / 2;
            }
            else if (buf % 2 == 1)
            {
                buf = buf * 3 + 1;
            }

            size++;
        }

        return size;
    }

    /* create pairs of Collatz sequence and root number up to limit */
    std::vector<std::pair<unsigned int, unsigned int>> createCollatzSizeLists(const unsigned int &limit)
    {
        return {{1, 1}};
    }

    /* output the root number creating longest Collatz sequence */
    unsigned int longest(const std::vector<std::pair<unsigned int, unsigned int>> &sizeLists)
    {
        return 10;
    }
}