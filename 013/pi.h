#include <utility>
#include <random>

/* monte carlo method */
namespace PI
{
    /* generate random point inside a unit square */
    std::pair<float, float> genRandomPoint();

    /* calc distance from origin to the point */
    float distance(std::pair<float, float> point);

    /* output PI calculated by monte carlo method*/    
    float calcPI(const unsigned int &samples);
}