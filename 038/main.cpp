/* 38. Temp log file */

/*
 * Features:
 * Output temp text log file.
 */

#include "logger.h"

int main(int argc, char const *argv[])
{
   Logger logger;
   logger << ("aaaaaaa");
   logger << ("bbbbbbb");
   logger << ("ccccccc");

   logger.save();

   return 0;
}