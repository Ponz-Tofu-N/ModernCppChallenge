/* 21. System Handle Wrapper (for Linux)*/

/*
 * Features:
 * 1. Get a Handle
 * 2. Release the Handle
 * 3. Validate the Handle
 * 4. Move the Handle
 */

#include "systemhandler.h"

#include <iostream>
#include <vector>
#include <array>

int main(int argc, char const *argv[])
{
    std::string file1Path("files/file1.txt");
    std::string file2Path("files/file2.txt");

    FileHandle handler = FileHandle(file1Path.c_str());
    FileHandle handler2 = FileHandle(file2Path.c_str());
    FileHandle handler3;

    constexpr unsigned int MAXSIZE = 1024u;
    std::vector<char> vec_str(MAXSIZE);
    std::array<char, MAXSIZE> arr_str;
    arr_str.fill(0);

    auto errMes = !handler ? "file not loaded" : "file loaded";

    std::cout << errMes << std::endl;

    read(handler.get(), arr_str.data(), MAXSIZE);

    std::cout << "file out put: ";
    for (auto c : arr_str)
    {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
