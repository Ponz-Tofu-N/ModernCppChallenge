/* 37. File list that matches regex pattern */

/*
 * Features:
 * Print file list.
 */

#include "directory.h"
#include <iostream>

int main(int argc, char const *argv[])
{
   std::string root{"./test"};
   std::regex re{R"(^(\w+).log)"};

   auto res = findByRegex(root, re);
   for (auto &&i : res)
   {
      std::cout << i << std::endl;
   }
   
   return 0;
}