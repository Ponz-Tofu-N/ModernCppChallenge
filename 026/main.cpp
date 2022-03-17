/* 26. Concatenate by with a Delimiter */

/*
 * Features:
 * - Concatenate the given text with a Delimiter.
 * - Delimiter: ' '(space)
 * - {"this", "is", "an", "example"} -> "this is an example"
 */

#include <iostream>
#include <vector>
#include <cassert>

#include "concatenate.h"

int main()
{
    std::vector<std::string> input1{"this", "is", "an", "example"};
    std::cout << concatenate(input1, " ") << std::endl;

    assert(concatenate(input1, " ") == "this is an example");
}
