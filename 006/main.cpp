// 6. Abundant Numbers
// Usage: Enter max number

#include <iostream>
#include <cmath>
#include <string>

int main(int argc, char const *argv[])
{
    std::cout << "input max number: ";
    unsigned int max; std::cin >> max;

    /*pick a num*/
    /*sum divisors*/
    /*print if abundant num and its abundance*/

    for (size_t i = max; i > 1; i--)
    {
        unsigned int sum = 0;
        const unsigned int limit = static_cast<unsigned int>(std::sqrt(i));
        
        for (size_t j = 1; j <= limit; j++)
        {
            if(i % j == 0){
                sum += j;
            }
        }

        if (sum > i)
        {
            std::cout   << "AbundantNum: " 
                        << i << " "
                        << "Abundant: "  
                        << sum - i * 2
                        << "\n";
        }
    }

    return 0;
}
