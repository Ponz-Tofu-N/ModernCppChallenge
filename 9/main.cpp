/*9. Prime Factorization */
/*Usage: Enter the target number.*/

#include <iostream>
#include <cmath>

bool isPrime(const int& target);

int main(int argc, char const *argv[])
{
    std::cout << "Enter num: ";

    unsigned int target;
    std::cin >> target;

    std::cout << "prime factorization: \n";
    
    auto temp = target;
    for (size_t i = 2; i <= target; i++)
    {
        if(!isPrime(i)) break;

        while (temp % i == 0)
        {
            std::cout << i << " ";
            temp = temp / i;
        }
    }
    std::cout << "\n";
    
    return 0;
}

bool isPrime(const int& target)
{
    auto root = static_cast<unsigned int>(std::sqrt(target));
    for (size_t i = 4; i <= root; i++)
    {
        if(target % i == 0)
        {
            return false;
        }
    }

    return true;
}
