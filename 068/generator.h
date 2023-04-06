#include <iostream>
#include <memory>
#include <random>
#include <vector>

class generator {
 public:
  generator(/* args */){};
  virtual ~generator(){};

  virtual std::string generate() = 0;
  virtual void add(std::unique_ptr<generator> g) = 0;
  virtual size_t length() = 0;
  virtual std::string allowed_char() = 0;
};

class password_generators : public generator {
 public:
  password_generators(/* args */);
  ~password_generators();

  virtual std::string generate() override final;
  virtual void add(std::unique_ptr<generator> g) override final;
  virtual size_t length() override final;
  virtual std::string allowed_char() override final;

 private:
  std::mt19937 engine;
  std::vector<std::unique_ptr<generator>> generators;
  std::string tokens = "abcdefghijklmnopqrstuvwxyz";
};
// 小文字
class basic_generator : public generator {
 protected:
  size_t len = 10;

 public:
  basic_generator(/* args */){};
  ~basic_generator(){};

  virtual std::string generate() override final;
  virtual void add(std::unique_ptr<generator> g) override final;
  virtual size_t length() override final;
};

// 大文字
class uppercase_generator : public basic_generator {
 private:
  /* data */
 public:
  uppercase_generator(const size_t _len) { len = _len; };
  ~uppercase_generator(){};

  virtual std::string allowed_char() override;
};
// 少なくとも一つの記号
class symbol_generator : public basic_generator {
 private:
  /* data */
 public:
  symbol_generator(const size_t _len) { len = _len; };
  ~symbol_generator(){};

  virtual std::string allowed_char() override;
};
// 数字
class number_generator : public basic_generator {
 private:
  /* data */
 public:
  number_generator(const size_t _len) { len = _len; };
  ~number_generator(){};

  virtual std::string allowed_char() override;
};
// class validator
// {
// public:
//   validator(){};
//   ~validator(){};

//   virtual void validate(const std::string_view password){};
// };

// class length_validator : public validator
// {
// private:
//   uint32_t limit = 8;

// public:
//   using validator::validator;
//   length_validator(const uint32_t _limit) : limit(_limit){};
//   ~length_validator(){};

//   void validate(const std::string_view password) override;
// };

// class pattern_validator : public validator
// {
// protected:
//   std::unique_ptr<validator> v;

// public:
//   using validator::validator;
//   ~pattern_validator(){};
// };

// class uppercase_validator : public pattern_validator
// {
// public:
//   uppercase_validator(){};
//   uppercase_validator(validator* inner) { v.reset(inner); };
//   ~uppercase_validator(){};

//   void validate(const std::string_view password) final override;
// };

// class digit_validator : public pattern_validator
// {
// public:
//   digit_validator(){};
//   digit_validator(validator* inner) { v.reset(inner); };
//   ~digit_validator(){};

//   void validate(const std::string_view password) final override;
// };
