#include <string>
#include <cmath>

namespace Temperature
{
    enum class UNIT
    {
        Celsius,
        Fahrenheit,
        Kelvin
    };

    template <UNIT U>
    class Quantity
    {
    private:
        double m_amount;
        UNIT m_unit = U;

        inline double getTemp() const noexcept
        {
            return m_amount;
        }

        inline UNIT getUnit() const noexcept
        {
            return m_unit;
        }

    public:
        Quantity(const double &temp)
            : m_amount(temp), m_unit(U)
        {
        }
        Quantity(const Quantity &temp)
            : m_amount(temp.getTemp()), m_unit(temp.getUnit())
        {
        }
        ~Quantity()
        {
        }

        std::string output()
        {
            switch (m_unit)
            {
            case UNIT::Celsius:
                return std::to_string(m_amount) + "C";
            case UNIT::Fahrenheit:
                return std::to_string(m_amount) + "F";
            case UNIT::Kelvin:
                return std::to_string(m_amount) + "K";
            }

            return std::string();
        }

        inline explicit operator double() const
        {
            return m_amount;
        }

        Quantity &operator+(const Quantity &other)
        {
            this->m_amount += other.m_amount;
            return *this;
        }
        Quantity &operator-(const Quantity &other)
        {
            this->m_amount -= other.m_amount;
            return *this;
        }

        bool operator==(const Quantity &other)
        {
            return this->m_amount == other.m_amount;
        }

        bool operator==(const double& other)
        {

            return (this->m_amount - other) < 1.0e-5;
        }

        bool operator<=(const Quantity &other)
        {
            return this->m_amount <= other.m_amount;
        }

        bool operator>=(const Quantity &other)
        {
            return this->m_amount >= other.m_amount;
        }
    };

    /* conversion from Kelvin to other */
    static Quantity<UNIT::Celsius> ktoc(Quantity<UNIT::Kelvin> k) noexcept
    {
        return Quantity<UNIT::Celsius>((double)k - 273.15e0);
    }
    static Quantity<UNIT::Fahrenheit> ktof(Quantity<UNIT::Kelvin> k) noexcept
    {
        return Quantity<UNIT::Fahrenheit>(((double)k - 273.15e0) * 1.8e0 + 32e0);
    }

    /* conversion from Celsius to other */
    static Quantity<UNIT::Kelvin> ctok(Quantity<UNIT::Celsius> c) noexcept
    {
        return Quantity<UNIT::Kelvin>((double)c + 273.15e0);
    }
    static Quantity<UNIT::Fahrenheit> ctof(Quantity<UNIT::Celsius> c) noexcept
    {
        return Quantity<UNIT::Fahrenheit>((double)c * 1.8e0 + 32e0);
    }

    /* conversion from Fahrenheit to other */
    static Quantity<UNIT::Celsius> ftoc(Quantity<UNIT::Fahrenheit> f) noexcept
    {
        return Quantity<UNIT::Celsius>(((double)f - 32e0) / 1.8e0);
    }
    static Quantity<UNIT::Kelvin> ftok(Quantity<UNIT::Fahrenheit> f) noexcept
    {
        return Quantity<UNIT::Kelvin>(((double)f - 32e0) / 1.8e0 + 273.15e0);
    }
}

namespace Temperature::literals
{
    inline Quantity<UNIT::Celsius> operator"" _deg(const long double temp)
    {
        return Quantity<UNIT::Celsius>(temp);
    }
    inline Quantity<UNIT::Fahrenheit> operator"" _f(const long double temp)
    {
        return Quantity<UNIT::Fahrenheit>(temp);
    }
    inline Quantity<UNIT::Kelvin> operator"" _k(const long double temp)
    {
        return Quantity<UNIT::Kelvin>(temp);
    }
}