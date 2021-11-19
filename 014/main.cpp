/*14. ISBN Validation*/
/*Usage: Enter 10 digit number.*/

#include <iostream>
#include "isbn.h"

int main(int argc, char const *argv[])
{
    std::cout << "Enter 10 digits code: ";

    std::string target;
    std::cin >> target;



    if (ISBN::validateIsbn(target))
    {
        std::cout << "Valid ISBN Code.\n";
    }
    else
    {
        std::cout << "Invalid ISBN Code.\n";
    }

    return 0;
}

