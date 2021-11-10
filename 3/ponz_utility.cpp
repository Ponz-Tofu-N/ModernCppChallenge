#include "ponz_utility.h"
namespace Util
{
    ui lcm(Util::ui& a, Util::ui& b)
    {
        return a * b / Util::gcd(a, b);
    }

    ui& gcd(Util::ui& a, Util::ui& b)
    {
        if(a < b) std::swap(a, b);

        while (b != 0)
        {
            Util::ui r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
}