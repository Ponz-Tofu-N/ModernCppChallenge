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

template <typename Comp, typename T>
T functionalCompare(Comp compare, T fst, T scd)
{
    return compare(fst, scd) ? fst : scd;
}

template <typename Comp, typename T, typename... Args>
T functionalCompare(Comp compare, T term, Args ...args)
{
    return functionalCompare(compare, term, functionalCompare(compare, args...));
}