template <typename... Args>
int minimum(int first, Args... args)
{
    int res = first;

    for (auto &&num : {args...})
    {
        if (num < res)
        {
            res = num;
        }
    }

    return res;
}