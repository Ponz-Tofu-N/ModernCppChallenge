// 2. GCD of two positive integers
// Usage: Enter 2 numbers.

#include <iostream>
#include <utility>

int main(int argc, char const *argv[])
{
    unsigned int first, second, bigger;
    std::cin >> first; std::cin >> second;

    if(first > second){
        bigger = first;
    }else{
        bigger = second;
    }

    unsigned int res = 0;
    for(unsigned int i = 1; i <= bigger; ++i){
        if((first % i | second % i ) == 0)
            res = i;
    }

    std::cout << res << "\n";
    return 0;
}
