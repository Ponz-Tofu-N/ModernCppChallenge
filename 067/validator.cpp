#include "validator.h"

void digit_validator::validate(const std::string_view password)
{
  std::string message = "NG";
  for (auto&& c : password)
  {
    if (std::isdigit(c))
    {
      message = "OK";
    }
  }

  std::cout << "digit : " << message << std::endl;

  if (v)
    v->validate(password);
}

void uppercase_validator::validate(const std::string_view password)
{
  std::string message = "NG";
  for (auto&& c : password)
  {
    if (std::isupper(c))
    {
      message = "OK";
    }
  }

  std::cout << "uppercase : " << message << std::endl;

  if (v)
    v->validate(password);
}

void length_validator::validate(const std::string_view password)
{
  std::string message = "NG";
  if (password.size() < limit)
    message = "OK";

  std::cout << "length : " << message << std::endl;
}