template <typename T, typename... Args>
T minimum(const T &first, Args &&...args)
{
    auto res = first;

    for (auto &&element : {args...})
    {
        if (element < res)
        {
            res = element;
        }
    }

    return res;
}