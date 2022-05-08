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
   auto resA = findByRegexA(root, re);

   for (auto &&e : res)
      std::cout << e << std::endl;

   for (auto &&e : resA)
      std::cout << e.path().filename() << std::endl;
   
   return 0;
}