
#include <string>
#include <fstream>
#include <algorithm>

void removeBlankLines(std::string in_path, std::string out_path)
{
    std::ifstream ifs(in_path);
    std::ofstream out(out_path, std::ios::app);

    for (std::string line; std::getline(ifs, line);)
    {
        if (line.size() > 0 && std::find_if(line.begin(), line.end(), [&](char c){return c == ' ' || c == '\0';}) == line.cend())
        {
            out << line << std::endl;;
        }
    }
}
