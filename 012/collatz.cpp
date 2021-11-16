#include "collatz.h"

namespace Collatz
{
    /* create the size of Collatz sequence with root num */
    unsigned int collatzSeqSize(const unsigned int &root)
    {
        int size = 1;
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

    /* Create a pair of the size of the largest collatz sequence and its root number. */
    std::pair<unsigned int, unsigned int> pairLargest( const unsigned int &limit)
    {
        unsigned int root = 1;
        unsigned int size = 1;
        
        for (size_t i = 2; i <= limit; i++)
        {
            int buf = Collatz::collatzSeqSize(i);
            if (buf > size)
            {
                root = i;
                size = buf;
            }
        }

        return std::make_pair(size, root);
    }
}