/* 34. Remove blank lines */

/*
 * Features:
 * before
 * ```
 * texttexttext
 * 
 * texttexttext
 * ```
 * after 
 * ```
 * texttexttext
 * texttexttext
 * ``` 
*/

#include "remove_blank_line.h"
#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::string in_path = "test.txt";
    std::string out_path = "test_out.txt";
    removeBlankLines(in_path, out_path);
    
    std::ifstream out(out_path);
    for (std::string line; std::getline(out, line);)
    {
        std::cout << line << std::endl;
    }
    
    return 0;
}
