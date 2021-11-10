/*8. Narcissistic Numbers up to 1000*/

#include <iostream>
#include <cmath>

struct Digit3
{
    unsigned int a, b, c;

    void make_elem(const int& num)
    {
        a = static_cast<unsigned int>(num / 100);
        b = static_cast<unsigned int>((num % 100) / 10);
        c = num % 10;
    }

    unsigned long eachPow()
    {
        return std::pow(a, 3) + std::pow(b, 3) + std::pow(c, 3);
    }

    void printDigits()
    {
        std::cout << a << " " << b << " " << c ;
    }

    Digit3(const int& initNum)
    {
        make_elem(initNum);
    }
};

int main(int argc, char const *argv[])
{
    std::cout << "narcissistic number: \n";

    for (size_t i = 100; i < 1000; i++)
    {
        Digit3 dt(i);
        if(dt.eachPow() == i)
        {
            std::cout << i << "\n";
        }
    }
    
    return 0;
}
