#include <string>
#include <sstream>

std::string find_palindrome(const std::string & input)
{
    std::istringstream iss(input);
    std::pair<size_t, size_t> resultInfo{0,0};

    // int begin, end;
    for (size_t i = 0; i < input.length(); i++)
    {
        int startpos = i;
        int lastpos = input.length();

        // 最後からinput[i]と同じ文字を探索
        lastpos = input.find_last_of(input.at(i), lastpos);

        // iまで行くとiを次の文字へ
        if (lastpos == i) continue;
        
        // 何かヒットしたら、i+nとj-nが同じか確認 (n=1,2,...,lastpos-i)
        for (size_t j = lastpos; j >= i; j--)
        {
            if (i == j && lastpos - i > resultInfo.second) 
                resultInfo = std::make_pair(i, lastpos - i + 1);

            auto startc = input.at(i + lastpos - j);
            auto endc = input.at(j);
            
            if (startc == endc)
            {
                continue;
            }
            else
            {
                break;                
            }
        }
    }

    return iss.rdbuf()->str().substr(resultInfo.first, resultInfo.second);
}
