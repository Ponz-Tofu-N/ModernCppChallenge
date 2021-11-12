/*10. Arabic to Roman */
/*Usage: Enter the target number up to 1000.*/

#include <iostream>
#include <array>
#include <algorithm>

/*std::mapは順番を管理しないのか、operator-がない。operator--はあるけど*/
int main(int argc, char const *argv[])
{
    std::array<std::pair<unsigned int, std::string>, 13> romanMap 
    {
        std::make_pair(1, "I"),
        std::make_pair(4, "IV"),
        std::make_pair(5, "V"),
        std::make_pair(9, "IX"),
        std::make_pair(10, "X"),
        std::make_pair(40, "XL"),
        std::make_pair(50, "L"),
        std::make_pair(90, "XC"),
        std::make_pair(100, "C"),
        std::make_pair(400, "CD"),
        std::make_pair(500, "D"),
        std::make_pair(900, "CM"),
        std::make_pair(1000, "M")
    };

    int target; std::cin >> target;
    std::cout << target << ": " ;

    std::string result;

    while (target > 0)
    {
        auto root = std::find_if(romanMap.begin(), romanMap.end(), [&](std::pair<unsigned int, std::string> pair)
        {
            return pair.first >= target;
        });

        if(root->first == target)
        {
            result += root->second;
            break;
        }
        else
        {
            result += (root - 1)->second;
            target -= (root - 1)->first;
        }
    }

    std::cout << result << "\n";

    return 0;
}

