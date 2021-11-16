#include <utility>
#include <vector>

namespace Collatz
{
    /* create the size of Collatz sequence with root num */
    unsigned int collatzSeqSize(const unsigned int &root);

    /* create pairs of Collatz sequence and root number up to limit */
    std::vector<std::pair<unsigned int, unsigned int>> createSizeLists(const unsigned int &limit);

    /* output the root number creating longest Collatz sequence */
    unsigned int longest(std::vector<const std::pair<unsigned int, unsigned int>> &sizeLists);
}