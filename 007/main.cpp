/*7. Amicable Numbers*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

class DivisorList
{
private:
    /* data */
    std::vector<unsigned int> divisorlist;

    void make_divisorlist(const int& limit)
    {
        /*1は必ず入る*/
        divisorlist.push_back(1);

        /*約数の最大値はsqrt(limit)であるため、limitの平方根を求める*/
        auto root = static_cast<int>(std::sqrt(limit));

        /*sqrt(limit)を超えない範囲で約数をリストに格納。必然的にlimit/iも約数になるためセットで格納。*/
        /*limit = 6, i = 2 のとき 6/2 = 3も約数*/
        for (unsigned int i = 2; i <= root; i++)
        {
            if(limit % i == 0)
            {
                divisorlist.push_back(i);
                divisorlist.push_back(limit / i);
            }
        }
    }

public:
    DivisorList(/* args */);
    DivisorList(const int& num);
    ~DivisorList();

    void printDivisorList()
    {
        for (auto num : divisorlist)
        {
            /* code */
            std::cout << num << " ";

        }
    }

    /*リストを足し合わせる*/
    unsigned long long sumDivisor()
    {
        return std::accumulate(divisorlist.begin(), divisorlist.end(), 0);
    }
};

DivisorList::DivisorList(/* args */)
{
}
DivisorList::DivisorList(const int& num)
{
    DivisorList::make_divisorlist(num);
}

DivisorList::~DivisorList()
{
}


int main(int argc, char const *argv[])
{
    std::cout << "input number: ";
    unsigned int limit; std::cin >> limit;

    for (size_t i = 1; i < limit; i++)
    {
        DivisorList dl_1st(i);
        auto sum = dl_1st.sumDivisor();

        DivisorList dl_2nd(sum);
        if (i == dl_2nd.sumDivisor() && i > sum)
        {
            std::cout << sum << ": " << i << "\n";
        }
    }

    return 0;
}
