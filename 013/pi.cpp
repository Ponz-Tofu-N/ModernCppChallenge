#include "pi.h"
#include <random>
#include <iostream>

namespace PI
{
    /* generate random point inside a unit square */
    std::pair<float, float> genRandomPoint()
    {
        std::random_device seed_gen;
        std::mt19937 ramdom(seed_gen());

        std::uniform_real_distribution<> dist(0.0f, 1.0f);

        return std::make_pair(dist(ramdom), dist(ramdom));
    }

    /* calc distance from origin to the point */
    float distance(std::pair<float, float> point)
    {
        return std::hypotf(point.first, point.second);
    }

    /* output PI calculated by monte carlo method*/
    /* (d/2)^2 * pi / d^2 = pi/4 */    
    float calcPI(const unsigned int &samples)
    {
        unsigned int inside = 0;
        for( int count = 0; count < samples; count++)
        {
            auto p = genRandomPoint();
            if (distance(p) <= 1)
            {
                inside++;
            }
        }

        return 4.0f * inside / samples;
    }
}
