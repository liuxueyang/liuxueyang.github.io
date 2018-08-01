// ==================================================

// C library
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>

// Containers
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Input/Output
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <ios>
#include <iomanip>

// Other
#include <tuple>
#include <string>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <iterator>
#include <limits>
#include <stdexcept>
#include <random>
#include <chrono>

// ==================================================

using namespace std;

// constants
const double EPS = 1e-9;

// type alias
using PII = pair<int, int>;
using VI = vector<int>;
using LL = long long int;
using VC = vector<char>;

// ==================================================

// fast IO
static auto __2333__ = []() {
                         ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

// ==================================================

// some macro for less typing
#define max_(x, y) ((x) > (y) ? (x) : (y))
#define min_(x, y) ((x) > (y) ? (y) : (x))

#define REP(i, n) for (int i = 0; i < int(n); ++i) // [0, n)
#define REPV(i, n) for (int i = int(n - 1); i >= 0; --i)   // reverse [0, n)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i) // [a, b)
#define DWN(i, b, a) for (int i = int(b - 1); i >= int(a); --i) // reverse [a, b)

#define REP_1(i, n) for (int i = 1; i <= int(n); ++i)           // [1, n]
#define REPV_1(i, n) for (int i = int(n); i >= 1; --i)          // reverse [1, n]
#define FOR_1(i, a, b) for (int i = int(a); i <= int(b); ++i)   // [a, b]
#define DWN_1(i, b, a) for (int i = int(b); i >= a; --i)        // reverse [a, b]

// DEBUG PRINT macro
#define PR(x) cout << #x " = " << (x) << "\t"
#define NL cout << "\n"

#define PR1(x) PR(x), NL
#define PR2(x1, x2) PR(x1), PR1(x2)
#define PR3(x1, x2, x3) PR(x1), PR2(x2, x3)
#define PR4(x1, x2, x3, x4) PR(x1), PR3(x2, x3, x4)

// ==================================================

// simplest print
template<typename T>
void PRC(const T& a) { cout << a << " "; }

// print container
template<typename T>
void PRCO(const T& c) { for (auto x : c) PRC(x); NL; }

// print vector
template<typename T>
void PRV(const vector<T>& c) { PRCO<vector<T>>(c); }

// print array, requires length
// TODO: use begin and end
template<typename T>
void PRA(const T ar[], int n) {
  for (int i = 0; i < n; ++i) PRC(ar[i]); NL;
}

// print pair
template<typename T1, typename T2>
void PRP(const pair<T1, T2>& p) { PRC(p.first); PRLN(p.second); }

// print a value and a new line
template<typename T>
void PRLN(const T& a) { cout << a << "\n"; }

// print a container, including a C-style array,
// but requires the first element to get element type
// TODO: Is it possible to remove the second argument?
template< typename T1, typename T2 >
void PRAV( T1 & vec, T2 x) {
  ostream_iterator< T2 > O( cout, " " );
  copy( begin( vec ), end( vec ), O ); NL;
}

// ==================================================
// math
bool is_prime(LL x)
{
  if (x == 1) return false;
  assert(x > 1);
  LL m = ceil(sqrt(x));
  FOR_1(i, 2, m) { if (!(x % i)) return false; }
  return true;
}

// high precision integer
const int BIGN_MAXN = 100000;

struct bign {
  int len, s[BIGN_MAXN];
  bign() { memset(s, 0, sizeof(s)); len = 1; }
  bign(int num) { *this = num; clean(); }
  bign(const char * num) { *this = num; clean(); }

  bign operator = (const char * num) {
    len = strlen(num);
    REP(i, len) { s[i] = num[len - 1 - i] - '0'; }
    clean();
    return *this;
  }

  bign operator = (int num) {
    char s[BIGN_MAXN];
    sprintf(s, "%d", num);
    *this = s; return *this;
  }

  string str() const {
    string res, t;
    REP(i, len) res = char(s[i] + '0') + res;
    return res == "" ? "0" : res;
  }

  bign operator + (const bign & b) const {
    bign c; c.len = 0;
    int max_len = max_(len, b.len), x;

    for (int i = 0, rem = 0; rem || i < max_len; i++) {
      x = rem;
      if (i < len) x += s[i];
      if (i < b.len) x += b.s[i];
      c.s[c.len++] = x % 10;
      rem = x / 10;
    }

    return c;
  }

  bign operator * (const bign & b) const {
    bign c; c.len = len + b.len;
    REP(i, len) REP(j, b.len) c.s[i + j] += s[i] * b.s[j];
    REP(i, c.len - 1) {
      c.s[i + 1] += c.s[i] / 10;
      c.s[i] %= 10;
    }
    c.clean();
    return c;
  }

  // assume *this >= b
  bign operator - (const bign & b) const {
    bign c; c.len = 0;
    int x;
    for (int i = 0, rem = 0; i < len; ++i) {
      x = s[i] - rem;
      if (i < b.len) x -= b.s[i];
      if (x >= 0) rem = 0;
      else { rem = 1; x += 10; }
      c.s[c.len++] = x;
    }
    c.clean();
    return c;
  }

  bign operator += (const bign & b) {
    *this = *this + b;
    return *this;
  }

  bool operator < (const bign & b) const {
    if (len != b.len) return len < b.len;
    REPV(i, len) if (s[i] != b.s[i]) return s[i] < b.s[i];

    return false;
  }

  bool operator > (const bign & b) const { return b < *this; }
  bool operator <= (const bign & b) const { return !(*this > b); }
  bool operator >= (const bign & b) const { return !(*this < b); }
  bool operator != (const bign & b) const { return b < *this || b > *this; }
  bool operator == (const bign & b) const { return !(b != *this); }

  // clean front zeros
  void clean() { while(len > 1 && !s[len - 1]) len--; }
};

istream & operator >> (istream & in, bign & x) {
  string s; in >> s; x = s.c_str();
  return in;
}

ostream & operator << (ostream & out, const bign & x) {
  out << x.str();
  return out;
}

class BNI {
  friend ostream &operator<<(ostream &, const BNI &);
  friend istream &operator>>(istream &, BNI &);
public:
  BNI() = default;
  BNI(const string &s) { *this = s; }
  BNI(const char s[]) :BNI(string(s)) {}
  BNI(const BNI &rhs) = default;
  BNI(LL n) { *this = n; };
  BNI(istream &in) { string s; in >> s; *this = s; }

  BNI &operator=(const BNI &rhs) = default;
  BNI &operator=(const string &s) {
    string s_ = clean_zero_str(s);
    num.resize(s_.size());
    int i = 0;
    // PR2("in operator=", num.size());
    for (auto it = s_.crbegin(); it != s_.crend(); ++it)
      num[i++] = *it - '0';
    return *this;
  }
  BNI &operator=(const char s[]) {
    operator=(string(s));
    return *this;
  }
  BNI &operator=(LL n) {
    stringstream ss; ss << n;
    string s; ss >> s;
    *this = s;
    return *this;
  }
  BNI operator+(const BNI &rhs) const {
    BNI res;
    size_t max_len = max_(num.size(), rhs.num.size());
    int x;
    for (int i = 0, rem = 0; rem || i < max_len; ++i) {
      x = rem;
      if (i < num.size()) x += num[i];
      if (i < rhs.num.size()) x += rhs.num[i];
      res.num.push_back(x % 10);
      rem = x / 10;
    }
    res.clean_zero();
    return res;
  }
  BNI& operator+=(const BNI &rhs) {
    *this = *this + rhs;
    return *this;
  }
  BNI operator*(const BNI &rhs) const {
    BNI res;
    size_t sum_len = num.size() + rhs.num.size();
    res.num.resize(sum_len);
    for (size_t i = 0; i < num.size(); ++i) {
      for (size_t j = 0; j < rhs.num.size(); ++j) {
        res.num[i + j] += num[i] * rhs.num[j];
      }
    }
    for (size_t i = 0; i < res.num.size() - 1; ++i) {
      res.num[i + 1] += res.num[i] / 10;
      res.num[i] %= 10;
    }
    res.clean_zero();
    return res;
  }
  BNI& operator*=(const BNI &rhs) {
    *this = *this * rhs;
    return *this;
  }
  /*
   * assume *this >= rhs
   */
  BNI operator-(const BNI &rhs) const {
    assert(*this >= rhs);
    BNI res;
    int x;
    for (int i = 0, rem = 0; i < num.size(); ++i) {
      x = num[i] - rem;
      if (i < rhs.num.size()) x -= rhs.num[i];
      if (x >= 0) rem = 0;
      else { rem = 1; x += 10; }
      res.num.push_back(x);
    }
    res.clean_zero();
    return res;
  }
  BNI& operator-=(const BNI &rhs) {
    *this = *this - rhs;
    return *this;
  }
  /*
   * assume rhs is not zero
   */
  pair<BNI, BNI> operator/(const BNI &rhs) const {
    // PR3("in operator/", *this, rhs);

    assert(BNI(0LL) != rhs);

    // PR3("in operator/", *this, rhs);

    if (*this < rhs) return make_pair(0LL, *this);

    BNI quotient, rem;
    string nume = c_str();
    string numerator = nume.substr(0, rhs.num.size());
    size_t pos = rhs.num.size();
    vector<BNI> times(10);
    for (int i = 0; i < 10; ++i) times[i] = rhs * i;
    // PRV(times);

    // PR3(numerator, pos, nume);
    string quot;

    while (pos <= nume.size()) {
      BNI nume_b = numerator;
      int cnt = 0;

      // PR1(nume_b);
      while (cnt < 10 && times[cnt] <= nume_b) ++cnt;
      --cnt;

      quot += char(cnt + '0');
      rem = nume_b - times[cnt];
      // PR2(cnt, rem);

      if (pos < nume.size())
        numerator = rem.c_str() + nume[pos];

      // PR1(pos);
      ++pos;
    }

    quotient = quot;
    // PR2(quotient, rem);

    return make_pair(quotient, rem);
  }
  bool operator<(const BNI &rhs) const {
    // PRLN("print two vectors:");
    // PRV(num);
    // PRV(rhs.num);
    
    if (num.size() == 0) return !(rhs.num.size() == 0);

    // PR3("in operator<", *this, rhs);
    // PRLN("--------");

    if (num.size() != rhs.num.size()) {
      // PRLN("in if");
      // PR2(num.size(), rhs.num.size());
      // PR1(num.size() < rhs.num.size());
      return num.size() < rhs.num.size();
    }

    // PRLN("before for");
    for (int i = num.size() - 1; i >= 0; --i) {
      if (num[i] != rhs.num[i]) return num[i] < rhs.num[i];
    }
    // PRLN("end for");
    return false;
  }
  bool operator>(const BNI &rhs) const { return rhs < *this; }
  bool operator<=(const BNI &rhs) const { return !(*this > rhs); }
  bool operator>=(const BNI &rhs) const { return !(*this < rhs); }
  bool operator!=(const BNI &rhs) const { return (*this < rhs) || (*this > rhs); }
  bool operator==(const BNI &rhs) const { return !(*this != rhs); }

private:
  vector<int> num;
  string clean_zero_str(const string &s) {
    if (s.empty() || s[0] != '0') return s;
    size_t i = 0;
    //        TODO: while (s[i++]) not work???
    while ('0' == s[i]) ++i;
    return s.substr(i);
  }
  void clean_zero() {
    for (auto it = num.rbegin(); it != num.rend() && *it == 0;) {
      ++it;
      num.pop_back();
    }
  }
  string c_str() const {
    string s;
    for (auto x : num) s = char(x + '0') + s;
    return s.empty() ? "0" : s;
  }
};

ostream &operator<<(ostream &out, const BNI &x) {
  out << x.c_str();
  return out;
}

istream &operator>>(istream &in, BNI &x) {
  x = BNI(in);
  return in;
}


// prime table
const int PRIME_MAX = 10000;
VI prime_table;
vector<bool> prime_table_bool(PRIME_MAX, true);

void get_prime() {
  FOR_1(i, 2, PRIME_MAX) {
    if (prime_table_bool[i]) {
      prime_table.push_back(i);
      for (int j = i << 1; j <= PRIME_MAX; j += i) prime_table_bool[j] = false;
    }
  }
}

// double equals
bool eq(double a, double b) { return fabs(a - b) < EPS; }

// ==================================================


int main( void ) {

#ifdef DEBUG
  freopen("10494_py.in", "r", stdin);
#endif

  string a, b, line, op;
  // while (cin >> a >> op >> b) {
  while (getline(cin, line)) {
    stringstream ss(line);
    ss >> a >> op >> b;
    BNI div, rem;

    auto x = BNI(a) / b;
    div = x.first;
    rem = x.second;

    if (op == "/") PRLN(div);
    else PRLN(rem);
  }

  return 0;
}
