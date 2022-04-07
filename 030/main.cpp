/* 30. URL parts extraction */

/*
 * Features:
 * URL string -> protcol, domain, port, path, query, fragment
 */

#include "extraction.h"

int main()
{
    std::string re(R"(^(\w+):\/\/([\w.-]+)\:?(\d+)?([\w\/\.]+)?\?([\w=&]*)?#?(/w+)?$)");
    std::string input1("https://www.touyube.com:80/watch?v=sJjZ4A_AAAA&ab_channel=AAA");

    auto actual = rx::parse_url(input1, re);

    std::cout << "protcol: " << actual->protcol << std::endl;
    std::cout << "domain: " << actual->domain << std::endl;
    
    if(actual->port.has_value())
        std::cout << "port: " << actual->port.value() << std::endl;
    if(actual->path.has_value())
        std::cout << "path: " << actual->path.value() << std::endl;
    if(actual->query.has_value())
        std::cout << "query: " << actual->query.value() << std::endl;
    if(actual->fragment.has_value())
        std::cout << "fragment: " << actual->fragment.value() << std::endl;

    return 0;
}
