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

using namespace Temperature::literals;

int main(int argc, char const *argv[])
{
    Temperature::Quantity<Temperature::UNIT::Celsius> tempc(12.435_deg);
    Temperature::Quantity<Temperature::UNIT::Fahrenheit> tempf(24.781_f);
    Temperature::Quantity<Temperature::UNIT::Kelvin> tempk(294.512_k);

    /* 24.781F -> -4.010556C */
    auto cfromf = Temperature::ftoc(tempf);
    /* 294.512K -> 21.362C */
    auto cfromk = Temperature::ktoc(tempk);

    /* 12.435C - 4.010556C + 21.362C = 29.786444*/
    auto outc = tempc + cfromf + cfromk;

    std::cout << outc.output() << std::endl;

    return 0;
}
