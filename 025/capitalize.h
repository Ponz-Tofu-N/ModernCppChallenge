#include <string>
#include <sstream>
#include <cctype>

std::string capitalize(const std::string & str)
{
    std::stringstream ss(str);
    std::string res;
    
    while (!ss.eof())
    {
        std::string block;
        ss >> block;

        block[0] = std::toupper(block[0]);

        for (size_t i = 1; i < block.size(); i++)
        {
            block[i] = std::tolower(block[i]);
        }
        
        // if( 'a' <= block[0] && block[0] <= 'z')
        // {
        //     block[0] = block[0] - 0x20;
        // }
        res.append(block);
        if(!ss.eof())
            res.append(" ");
    }

    return res;
}