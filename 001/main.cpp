// 1. Sum of integers divisible by 3 or 5
// Usage: Enter a root number.

#include <iostream>

int main(int argc, char const *argv[])
{
    unsigned long long input, sum = 0; std::cin >> input;
    
    for(unsigned long long i = 1; i <= input; i++){
        if(i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    std::cout << sum << "\n";
    return 0;
}

// 3, 5, 6, 9, 10