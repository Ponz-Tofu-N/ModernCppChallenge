#include <utility>
#include <random>

/* monte carlo method */
namespace PI
{
    /* generate random point inside a square with a side of the given length */
    std::pair<float, float> genRandomPoint();

    /* calc distance from origin*/
    float distance(std::pair<float, float> point);

    /* output PI calculated by monte carlo method*/    
    float calcPI(const unsigned int &coordinates);
}