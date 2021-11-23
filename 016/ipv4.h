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
    /*operator<<, >>はメンバ関数ではないため、friendを付ける*/
    /*friend関数は、メンバ以外の関数であってもメンバにアクセスできる*/
    friend std::ostream& operator<<(std::ostream& os, const Ipv4& ip);
    friend std::istream& operator>>(std::istream& is, Ipv4& ip);

    /* assignment operator */
    Ipv4& operator=(const Ipv4& other);
    
    /*increment operator*/
    Ipv4& operator++();

    /*comparison operator*/
    friend bool operator<(const Ipv4& fst, const Ipv4& scd);
    friend bool operator==(const Ipv4& fst, const Ipv4& scd);
};

