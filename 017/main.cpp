/* 17. 2-dimensional array */

#include <iostream>
#include "array2d.h"

int main(int argc, char const *argv[])
{
    /* リスト初期化子は2重に{}が必要 */
    Array2d<int, 3, 4> arr1 = 
    {
        {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12}
        }
    };

    Array2d<int, 3, 4> arr2 = 
    {
        {
            {13,14,15,16},
            {17,18,19,20},
            {21,22,23,24}        
        }
    };

    std::cout << "array1:\n";
    arr1.output();
    
    std::cout << "array2:\n"; 
    arr2.output();

    std::cout << "data(1,0): " << arr1.data(1, 0) << std::endl;
    std::cout << "size: " << arr1.size() << std::endl;

    arr1.swap(arr2);

    std::cout << "swapped array1:\n";
    arr1.output();
    
    std::cout << "swapped array2:\n"; 
    arr2.output();

    std::cout << "size: " << arr1.size() << std::endl;

    auto itr_begin = arr1.begin();
    std::cout << "itr begin: " << *itr_begin << std::endl;

    auto itr_end = arr1.end();
    std::cout << "itr end: " << *itr_end << std::endl;

    return 0;
}

