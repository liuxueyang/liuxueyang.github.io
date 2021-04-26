#include <string>
#include <iostream>

using namespace std;

class Sales_data {
  friend istream& read(istream&, Sales_data&);
  friend ostream& print(ostream&, const Sales_data&);
  friend istream& operator>>(istream&, Sales_data&);
  friend ostream& operator<<(ostream&, const Sales_data&);
  friend Sales_data add(const Sales_data&, const Sales_data&);

 public:
  Sales_data() = default;

  Sales_data(const string &s, unsigned n, double p) :
    bookNo(s), units_sold(n), revenue(p) { }

  Sales_data(istream& is) {
    read(is, *this);
  }

  Sales_data(const Sales_data& rhs) :
    bookNo(rhs.bookNo),
    units_sold(rhs.units_sold),
    revenue(rhs.revenue) { }

  Sales_data& combine(const Sales_data &rhs);

  Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
  }

  Sales_data operator+(const Sales_data &rhs) {
    return add(*this, rhs);
  }

  Sales_data& operator+=(const Sales_data& rhs) {
    return combine(rhs);
  }

  Sales_data& operator=(const Sales_data&);

  string isbn() const {
    return bookNo;
  }

 private:
  double avg_price() const {
    return units_sold ? revenue / units_sold : 0;
  }

  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

istream& read(istream&, Sales_data&);
ostream& print(ostream&, const Sales_data&);
istream& operator>>(istream&, Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);

istream& read(istream& is, Sales_data& item) {
  double price = 0;

  is >> item.bookNo >> item.units_sold >> price;
  if (is) {
    item.revenue = price * item.units_sold;
  } else {
    item = Sales_data();
  }

  return is;
}

ostream& print(ostream& os, const Sales_data& item) {
  os << item.isbn() << ' ' << item.units_sold << ' '
     << item.revenue << ' ' << item.avg_price();

  return os;
}

istream& operator>>(istream& is, Sales_data& item) {
  return read(is, item);
}

ostream& operator<<(ostream& os, const Sales_data& item) {
  return print(os, item);
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;

  return *this;
}

Sales_data& Sales_data::operator=(const Sales_data &rhs) {
  bookNo = rhs.bookNo;
  units_sold = rhs.units_sold;
  revenue = rhs.revenue;

  return *this;
}
