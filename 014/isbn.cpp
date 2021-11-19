#include "isbn.h"

namespace ISBN
{
    /* Convert char to int */
    int ctoi(char _digit)
    {
        return static_cast<int>(_digit - '0');
    }

    /* validate target if it's ISBN code. */
    bool validateIsbn(const std::string &_target)
    {
        int i = 10;
        int sum = std::accumulate(_target.begin(), _target.end() - 1, 0,
                                  [&i](int acc, const char digit)
                                  {
                                      if (digit != 'X' || digit != '-')
                                          acc += ctoi(digit) * i--;
                                      return acc;
                                  });

        int c = 11 - (sum % 11);
        if (c == 10 && _target.back() == 'X')
            return true;

        if (c == ctoi(_target.back()))
            return true;

        return false;
    }
}