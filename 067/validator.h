#include <iostream>
#include <memory>

class validator
{
public:
  validator(){};
  ~validator(){};

  virtual void validate(const std::string_view password){};
};

class length_validator : public validator
{
private:
  uint32_t limit = 8;

public:
  using validator::validator;
  length_validator(const uint32_t _limit) : limit(_limit){};
  ~length_validator(){};

  void validate(const std::string_view password) override;
};

class pattern_validator : public validator
{
protected:
  std::unique_ptr<validator> v;

public:
  using validator::validator;
  ~pattern_validator(){};
};

class uppercase_validator : public pattern_validator
{
public:
  uppercase_validator(){};
  uppercase_validator(validator* inner) { v.reset(inner); };
  ~uppercase_validator(){};

  void validate(const std::string_view password) final override;
};

class digit_validator : public pattern_validator
{
public:
  digit_validator(){};
  digit_validator(validator* inner) { v.reset(inner); };
  ~digit_validator(){};

  void validate(const std::string_view password) final override;
};
