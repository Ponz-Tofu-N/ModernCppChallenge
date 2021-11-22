#include <vector>
#include <string>

class Ipv4
{
private:
    std::vector<std::uint8_t> adress;

public:
    Ipv4();
    
    /* Constructor with 4 bytes */
    Ipv4(const std::uint8_t a,
         const std::uint8_t b,
         const std::uint8_t c,
         const std::uint8_t d);

    /* Constructor with string */
    Ipv4(const std::string & input);

    /*　copy constructor*/
    Ipv4(const Ipv4 & other);

    ~Ipv4();

    /* output ip adress */
    std::string output();

    /*operator-overload for iostream*/
    friend std::ostream& operator<<(std::ostream& os, const Ipv4& ip);
    friend std::istream& operator>>(std::istream& is, Ipv4& ip);
};

