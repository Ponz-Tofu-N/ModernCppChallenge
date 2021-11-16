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
}