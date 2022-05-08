/* 36. Delete older files */

/*
 * Features:
 * Delete older files
 */

#include "directory.h"
#include <iostream>

int main(int argc, char const *argv[])
{
   std::string path{"./test"};

   using namespace std::chrono_literals;
   remove_file(path, 7 * 24h + 20min);

   return 0;
}