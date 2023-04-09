#include "ssn_generator.h"

#include <random>
#include <sstream>
#include <stdexcept>

unsigned int northeria_generator::sex(const ssn_generator::sex_type s)
{
  switch (s)
  {
    case ssn_generator::sex_type::Female:
      return 9;
    case ssn_generator::sex_type::Male:
      return 7;

    default:
      throw std::invalid_argument("invalid augument: Sex");
      break;
  }

  return 0;
}

unsigned int northeria_generator::random_number(const uint32_t year,
                                                const uint32_t month,
                                                const uint32_t day)
{
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  // 0以上9以下の値を等確率で発生させる
  std::uniform_int_distribution<> dist(0, 9);

  int nnnnn = 0;
  while (true)
  {
    for (size_t i = 1; i < std::pow(10.0, 5.0); i *= 10)
    {
      nnnnn += i * dist(engine);
    }
    std::stringstream date;
    date << year << month << day;
    if (cache.find(date.str()) == std::cend(cache))
    {
      cache[date.str()] = nnnnn;
      return nnnnn;
    }
  }

  return nnnnn;
}

uint32_t northeria_generator::modulo() { return 11; }

unsigned int southeria_generator::sex(const ssn_generator::sex_type s)
{
  switch (s)
  {
    case ssn_generator::sex_type::Female:
      return 1;
    case ssn_generator::sex_type::Male:
      return 2;

    default:
      throw std::invalid_argument("invalid augument: Sex");
      break;
  }

  return 0;
}

unsigned int southeria_generator::random_number(const uint32_t year,
                                                const uint32_t month,
                                                const uint32_t day)
{
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());

  // 0以上9以下の値を等確率で発生させる
  std::uniform_int_distribution<> dist(0, 9);

  int nnnn = 0;
  while (true)
  {
    for (size_t i = 1; i < std::pow(10.0, 4.0); i *= 10)
    {
      nnnn += i * dist(engine);
    }
    std::stringstream date;
    date << year << month << day;
    if (cache.find(date.str()) == std::cend(cache))
    {
      cache[date.str()] = nnnn;
      return nnnn;
    }
  }

  return nnnn;
}

uint32_t southeria_generator::modulo() { return 10; }

unsigned int ssn_generator::checksum(std::string_view ssn)
{
  size_t i = ssn.size();
  size_t checksum = 0;
  for (auto &&digit : ssn)
  {
    checksum += i * (digit - '0');
    i--;
  }

  return checksum;
}

std::string ssn_generator::generate(const sex_type s,
                                    const uint32_t year,
                                    const uint32_t month,
                                    const uint32_t day)
{
  std::stringstream ssn;
  ssn << sex(s);
  ssn << year << month << day;
  ssn << random_number(year, month, day);

  auto crc = checksum(ssn.str());
  ssn << modulo() - (crc % modulo());

  return ssn.str();
}