#include <vector>

template <typename T, typename... Args>
void push_back_variadic(T& vec, const Args&&... args)
{
    for (auto &&arg : {args...})
    {
        vec.push_back(arg);
    }
}