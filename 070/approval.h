#include <memory>
#include <string>

class role
{
public:
  virtual size_t limit() = 0;
  virtual ~role() {}
};

class employee_role : public role
{
public:
  virtual size_t limit() override final;
};
class team_manager_role : public role
{
public:
  virtual size_t limit() override final;
};
class department_manager_role : public role
{
public:
  virtual size_t limit() override final;
};
class president_role : public role
{
public:
  virtual size_t limit() override final;
};

class expense
{
private:
  size_t amount;
  std::string desc;

public:
  expense(size_t const _amount, std::string const &_desc)
      : amount(_amount), desc(_desc){};
  ~expense(){};

  size_t cost() const { return amount; };
  std::string description() const { return desc; }
};

class employee
{
  std::string name;
  std::shared_ptr<employee> direct_manager;
  std::unique_ptr<role> own_role;

public:
  explicit employee(std::string const &_name, std::unique_ptr<role> _role)
      : name(_name), own_role(std::move(_role))
  {
  }
  ~employee() {}
  void approve(expense const &e);
  void set_direct_manager(std::shared_ptr<employee> dm);
};
