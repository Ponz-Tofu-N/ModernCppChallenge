#include <map>
#include <string>

class ssn_generator
{
public:
  enum class sex_type
  {
    Female,
    Male
  };
  virtual uint32_t sex(const ssn_generator::sex_type s) = 0;
  virtual uint32_t random_number(const uint32_t year,
                                 const uint32_t month,
                                 const uint32_t day) = 0;
  virtual uint32_t modulo() = 0;

  uint32_t checksum(std::string_view ssn);
  std::string generate(const sex_type sex,
                       const uint32_t year,
                       const uint32_t month,
                       const uint32_t day);

  ssn_generator(){};
  ~ssn_generator(){};

protected:
  std::map<std::string, uint32_t> cache;
};

class northeria_generator : public ssn_generator
{
public:
  using ssn_generator::ssn_generator;
  ~northeria_generator(){};

  virtual uint32_t sex(const ssn_generator::sex_type s) override final;
  virtual uint32_t random_number(const uint32_t year,
                                 const uint32_t month,
                                 const uint32_t day) override final;
  virtual uint32_t modulo() override final;
};

class southeria_generator : public ssn_generator
{
public:
  using ssn_generator::ssn_generator;
  ~southeria_generator(){};

  virtual uint32_t sex(const ssn_generator::sex_type s) override final;
  virtual uint32_t random_number(const uint32_t year,
                                 const uint32_t month,
                                 const uint32_t day) override final;
  virtual uint32_t modulo() override final;
};
