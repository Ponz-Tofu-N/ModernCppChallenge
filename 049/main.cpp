#include <iostream>
#include <iomanip>
#include <numeric>
#include "most_frequent.h"

int main()
{
   auto result = analyze_text(R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.)");

   for (auto const & kvp : result)
   {
      std::cout
         << kvp.first << " : "
         << std::fixed
         << std::setw(5) << std::setfill(' ')
         << std::setprecision(2) << kvp.second << std::endl;
   }

   std::cout
      << "Total: "
      << std::accumulate(result.begin(), result.end(), 0e0, [](double acc, auto i){
         return acc += i.second;
      }) << std::endl;
}
