/*10. Gray Code */
/*Output binary, Gray code and decoded Gray code */
/*Usage: Enter the target number.*/

#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
const std::string make_bit5(T target)
{
    std::string bit_str;
    int count = 0;

    while (count < 5)
    {
        bit_str.push_back((target & 1) ? '1' : '0');
        target >>= 1;
        count++;
    }

    std::reverse(bit_str.begin(), bit_str.end());
    
    return bit_str;

}

template <typename T>
const std::string make_gray5(T target)
{
    auto graycode = target ^ (target >> 1);
    
    return make_bit5(graycode);
}

const std::string decode_gray5(const std::string& gray)
{
    std::string decodedGray;
    auto itr = gray.begin();    

    if(*itr)
    {
        decodedGray.push_back('1');
    }
    else
    {
        decodedGray.push_back('0');
    }

    while (itr != gray.end())
    {
        if(decodedGray.size() == 5) break;
        
        if(*itr != *(itr + 1))
        {
            decodedGray.push_back('1');
        }
        else
        {
            decodedGray.push_back('0');
        }

        itr++;
    }

    std::reverse(decodedGray.begin(), decodedGray.end());

    return decodedGray;
}

int main(int argc, char const *argv[])
{
    /*std::uint8_tで試したが、右シフト演算の時に1が追加されるためunsigned shortで対応した。*/
    unsigned short target; std::cin >> target;

    std::cout <<"binary code: "<< make_bit5(target) << "\n";
    std::cout <<"gray code: "<< make_gray5(target) << "\n";
    std::cout <<"decoded gray code: "<< decode_gray5(make_gray5(target)) << "\n";

    std::cout << "\n";
    return 0;
}