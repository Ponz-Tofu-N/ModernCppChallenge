#include <iostream>
#include <memory>


class validator
{
protected:
  std::unique_ptr<validator> v;

public:
  validator() = default;
  validator(validator* inner);
  ~validator();

  virtual void validate(){};
};

validator::validator(validator* inner)
    :v(inner)
{
}

validator::~validator()
{
}

class length_validator : public validator
{
private:
    /* data */
public:
    using validator::validator;
    ~length_validator(){};

    void validate() override;
};

void length_validator::validate()
{
    std::cout << "length : OK" << std::endl;
    
    if (v) v->validate();
}

class number_validator : public validator
{
private:
    /* data */
public:
    using validator::validator;
    ~number_validator(){};

    void validate() override;
};

void number_validator::validate()
{
    std::cout << "number : OK" << std::endl;
    if (v) v->validate();
}