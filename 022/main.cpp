/* 22. Various Temperature units*/

/*
 * Features:
 * 1. output Celsius, Fahrenheit and Kelvin scales.
 * 2. Celsius: 36.5_deg, Fahrenheit: 97.7_f, Kelvin 309.65_K.
 * 3. Conversion temperature unit to units.
 * 4. Calculate each units.
 */

/* User-defined literal */
/* https://cpprefjp.github.io/lang/cpp11/user_defined_literals.html */


#include <iostream>
#include <vector>
#include <array>

#include "temperature.h"

int main(int argc, char const *argv[])
{
    Temperature<UNIT::Celsius> tempc1(12.435);
    Temperature<UNIT::Celsius> tempc2(24.781);

    auto tempc = tempc1 + tempc2;

    std::cout << tempc.output() << std::endl;

    return 0;
}
