#include <string>
#include <iostream>
#include <vector>

void print_ptriangle(const int steps = 10)
{
    const int IMAX = 2 * steps - 1;
    const int JMAX = steps;

    std::vector<int> output(JMAX * IMAX);

    std::fill(output.begin(), output.end(), 0);

    output[IMAX / 2] = 1;

    for (size_t j = 1; j < JMAX; j++)
    {
        for (size_t i = 0; i < IMAX; i++)
        {
            int upperL, upperR;

            if ((i - 1) == -1)
            {
                upperL = 0;
                upperR = output[IMAX * (j - 1) + (i + 1)];
            }
            else if (i + 1 == IMAX)
            {
                upperL = output[IMAX * (j - 1) + (i - 1)];
                upperR = 0;
            }
            else
            {
                upperL = output[IMAX * (j - 1) + (i - 1)];
                upperR = output[IMAX * (j - 1) + (i + 1)];
            }

            if (upperL != 0 || upperR != 0)
            {
                output[IMAX * j + i] = upperL + upperR;
                i++;
            }
        }
    }

    for (size_t i = 0; i < output.size(); i++)
    {
        if (output[i] == 0) 
        {
            std::cout << ' ';
        }
        else
        {
            std::cout << output[i];
        }
        
        if (i % IMAX == IMAX - 1)
            std::cout << "\n";
    }
}