#include <numeric>
#include <string>

namespace ISBN
{
    /* Convert char to int */
    inline int ctoi(char _digit);

    /* validate target if it's ISBN code. */
    bool validateIsbn(const std::string &_target);
}