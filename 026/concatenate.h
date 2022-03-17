#include <string>
#include <sstream>
#include <iterator>

template <class C>
std::string concatenate(const C &container, const char* delimiter)
{
    std::stringstream res;
    std::copy(container.begin(), container.end() - 1, std::ostream_iterator<std::string>(res, " "));
    auto itr = container.cend();
    res << *(itr - 1);

    return res.rdbuf()->str();
}