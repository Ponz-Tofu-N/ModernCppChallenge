#include <iostream>
#include <algorithm>
template <typename C, typename... Args>
bool all(const C &cont, const Args &...args)
{
    C argsCont{args...};
    if (cont != argsCont)
    {
        return false;
    }

    return true;
}

template <typename C, typename... Args>
bool any(C cont, Args... args)
{
    for (auto &&e : {args...})
    {
        auto itr = std::find(cont.begin(), cont.end(), e);

        if (itr == cont.cend())
        {
            return false;
        }
    }

    return true;
}

template <typename C, typename... Args>
bool none(C cont, Args... args)
{
    for (auto &&e : {args...})
    {
        auto itr = std::find(cont.begin(), cont.end(), e);

        if (itr != cont.cend())
        {
            return false;
        }
    }

    return true;
}