#include <utility>
#include <vector>

namespace Collatz
{
    /* create the size of Collatz sequence with root num */
    unsigned int collatzSeqSize(const unsigned int &root);

    /* Create a pair of the size of the largest collatz sequence and its root number. */
    std::pair<unsigned int, unsigned int> pairLargest( const unsigned int &limit);
}