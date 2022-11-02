class customer
{
private:
  int ticket_id;

public:
  customer(const int ticket);
  ~customer();

  int ticket() { return ticket_id; }

  friend bool operator<(const customer& l, const customer& r)
  {
    return l.ticket_id > r.ticket_id;
  }
};

customer::customer(const int ticket) : ticket_id(ticket) {}

customer::~customer() {}
