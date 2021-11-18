/*14. ISBN Validation*/
/*Usage: Enter 10 digit number.*/

#include <iostream>

int ctoi(char digit)
{
    return static_cast<int>(digit - '0');
}

bool validateCheckDigit(const int& sum, const char checkDigit)
{
    int c = 11 - (sum % 11);
    if(c == 10)
    {
        if (checkDigit == 'X')
            return true;

        return false;
    }

    if (c == ctoi(checkDigit))
        return true;

    return false;
}

int main(int argc, char const *argv[])
{
    std::cout << "Enter 10 digits code: ";

    std::string target;
    std::cin >> target;

    while (target.size() != 10)
    {
        std::cout << "Not 10 digits.\n";
        std::cout << "Enter again: ";
        std::cin >> target;
    }

    int sum = 0;
    auto str_itr = target.begin();
    for (int i = 10; i > 1; i--)
    {
        sum += ctoi(*str_itr) * i;
        str_itr++;
    }

    if (validateCheckDigit(sum, target.back()))
    {
        std::cout << "Valid ISBN Code.\n";
    }
    else
    {
        std::cout << "Invalid ISBN Code.\n";
    }

    return 0;
}

