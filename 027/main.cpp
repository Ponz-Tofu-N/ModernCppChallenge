/* 26. Split a text into tokens with delimiter */

/*
 * Features:
 * - Delimiter: ' '(space) or '.'(dot) or ','(comma)
 * - "this is an example" -> {"this", "is", "an", "example"}
 */

#include <iostream>
#include <vector>
#include <cassert>

#include "split.h"

static inline void output(std::vector<std::string> v)
{
    for (auto &&i : v)
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    std::string input1{"this is an example"};
    std::string input2{"this,is an!example"};

    auto output1 = split<std::vector<std::string>>(input1, ' ');
    auto output2 = split<std::vector<std::string>>(input2, " ,!");
    output(output1);
    output(output2);

    assert(output1 == std::vector<std::string>({"this", "is", "an", "example"}));
    assert(output2 == std::vector<std::string>({"this", "is", "an", "example"}));
}
