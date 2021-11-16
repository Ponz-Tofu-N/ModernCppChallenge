#include "pi.h"
#include <random>
#include <iostream>

namespace PI
{
    /* generate random point inside a square with a side of the given length */
    std::pair<float, float> genRandomPoint()
    {
        std::random_device seed_gen;
        std::mt19937 ramdom(seed_gen());

        auto first = 1.0f * ramdom() / ramdom.max();
        auto second = 1.0f * ramdom() / ramdom.max();

        return std::make_pair(first, second);
    }

    /* calc distance from origin*/
    float distance(std::pair<float, float> point)
    {
        return std::hypotf(point.first, point.second);
    }

    /* output PI calculated by monte carlo method*/
    /* (d/2)^2 * pi / d^2 = pi/4 */    
    float calcPI(const unsigned int &coordinates)
    {
        unsigned int inside = 0;
        unsigned int outside = 0;

        for( int count = 0; count < coordinates; count++)
        {
            auto p = genRandomPoint();
            if (distance(p) <= 1)
            {
                inside++;
            }
            else
            {
                outside++;
            }
        }

        return 4.0f * inside / coordinates;
    }
}