/* 30. URL parts extraction */

/*
 * Features:
 * URL string -> protcol, domain, port, path, query, fragment
 */

#include "rxdate.h"

int main()
{
    std::string input1("21-03-1289");
    std::string input2("21.03.1289");
    std::cout << "input1: " << input1 << std::endl;
    std::cout << "input2: " << input2 << std::endl;

    std::string re(R"(^(\w{2})(-|.)(\w{2})(-|.)(\w{4})$)");

    auto parsed1 = rx::parseDate(input1, re);
    auto parsed2 = rx::parseDate(input2, re);

    std::cout << "parsed1: " << rx::parseDate(input1, re) << std::endl;
    std::cout << "parsed2: " << rx::parseDate(input2, re) << std::endl;
    
    return 0;
}
