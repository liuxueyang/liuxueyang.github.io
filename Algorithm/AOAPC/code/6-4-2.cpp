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

// print C-style array
template<typename T, size_t N>
void PRA(const T (&ar)[N]) {
  for (auto x : ar) PRC(x); NL;
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

class BNI {
  friend ostream &operator<<(ostream &, const BNI &);
  friend istream &operator>>(istream &, BNI &);
public:
  BNI() = default;
  BNI(const string &s) { *this = s; }
  BNI(const char s[]) :BNI(string(s)) {}
  BNI(const BNI &rhs) = default;
  BNI(const LL n) { *this = n; };
  BNI(istream &in) { string s; in >> s; *this = s; }

  BNI &operator=(const BNI &rhs) = default;
  BNI &operator=(const string &s) {
    string s_ = clean_zero_str(s);
    num.resize(s_.size());
    int i = 0;
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
    if (rhs == 0LL) return *this;
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
    assert(BNI(0LL) != rhs);
    if (*this < rhs) return make_pair(0LL, *this);

    BNI quotient, rem;
    string nume = c_str();
    string numerator = nume.substr(0, rhs.num.size());
    size_t pos = rhs.num.size();
    vector<BNI> times(10);
    for (int i = 0; i < 10; ++i) times[i] = rhs * i;
    string quot;

    while (pos <= nume.size()) {
      BNI nume_b = numerator;
      int cnt = 0;

      while (cnt < 10 && times[cnt] <= nume_b) ++cnt;
      --cnt;

      quot += char(cnt + '0');
      rem = nume_b - times[cnt];

      if (pos < nume.size())
        numerator = rem.c_str() + nume[pos];

      ++pos;
    }

    quotient = quot;

    return make_pair(quotient, rem);
  }
  bool operator<(const BNI &rhs) const {
    if (num.size() == 0) return !(rhs.num.size() == 0);
    if (num.size() != rhs.num.size()) {
      return num.size() < rhs.num.size();
    }
    for (int i = num.size() - 1; i >= 0; --i) {
      if (num[i] != rhs.num[i]) return num[i] < rhs.num[i];
    }
    return false;
  }
  bool operator>(const BNI &rhs) const { return rhs < *this; }
  bool operator<=(const BNI &rhs) const { return !(*this > rhs); }
  bool operator>=(const BNI &rhs) const { return !(*this < rhs); }
  bool operator!=(const BNI &rhs) const { return (*this < rhs) || (*this > rhs); }
  bool operator==(const BNI &rhs) const { return !(*this != rhs); }
  size_t size() const { return num.size(); }
  string c_str() const {
    string s;
    for (auto x : num) s = char(x + '0') + s;
    return s.empty() ? "0" : s;
  }
  void left_shift() {
    if (!num.empty()) num.pop_back();
  }
protected:
  vector<int> num;
  string clean_zero_str(const string &s) {
    if (s.empty() || s[0] != '0') return s;
    size_t i = 0;
    while (i < s.size() && '0' == s[i]) ++i;
    return s.substr(i);
  }
  void clean_zero() {
    for (auto it = num.rbegin(); it != num.rend() && *it == 0;) {
      ++it;
      num.pop_back();
    }
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

class BNF : protected BNI {
  friend ostream &operator<<(ostream &out, const BNF &x);
  friend istream &operator>>(istream &in, BNF &x);
public:
  BNF() = default;
  BNF(const string &s) { *this = s; }
  BNF(const char s[]): BNF(string(s)) {}
  BNF(const BNF &rhs) = default;
  BNF(const LL n) { *this = n; }
  BNF(istream &in) { string s; in >> s; *this = s; }

  BNF &operator=(const string &s) {
    string s_ = clean_zero_str(s);
    num.resize(s_.size());
    int i = 0;
    for (auto it = s_.crbegin(); it != s_.crend(); ++it)
      num[i++] = *it - '0';
    return *this;
  }
  BNF &operator=(const char s[]) {
    operator=(string(s)); return *this;
  }
  BNF &operator=(LL n) {
    stringstream ss; ss << n;
    string s; ss >> s;
    *this = s;
    return *this;
  }
  BNF operator+(const BNF &rhs) const {
    pair<string, string> in_fr1 = split(), in_fr2 = rhs.split();
    string inte1 = in_fr1.first, frac1 = in_fr1.second,
      inte2 = in_fr2.first, frac2 = in_fr2.second;
    LL inc = 0LL;
    BNI frac_sum;
    inc += sum_has_carry(frac1, frac2, frac_sum);
    BNI inte_sum = BNI(inte1) + inte2 + inc;

    return join_inte_frac(inte_sum, frac_sum);
  }
  BNF& operator+=(const BNF &rhs) {
    *this = *this + rhs;
    return *this;
  }
  /*
   * assume *this >= rhs
   */
  BNF operator-(const BNF &rhs) const {
    assert(*this >= rhs);
    pair<string, string> in_fr1 = split(), in_fr2 = rhs.split();
    string inte1 = in_fr1.first, frac1 = in_fr1.second,
      inte2 = in_fr2.first, frac2 = in_fr2.second;
    LL dec = 0LL;
    if (BNI(frac1) < frac2) {
      frac1 = '1' + frac1; ++dec;
    }
    while (frac1.size() < frac2.size()) frac1 += '0';
    while (frac2.size() < frac1.size()) frac2 += '0';
    BNI frac = BNI(frac1) - frac2;
    BNI inte = BNI(inte1) - dec - inte2;
    return join_inte_frac(inte, frac);
  }
  BNF& operator-=(const BNF &rhs) {
    return *this = *this - rhs;
  }
  BNF operator*(const BNF &rhs) const {
    pair<string, string> in_fr1 = split(), in_fr2 = rhs.split();
    string inte1 = in_fr1.first, frac1 = in_fr1.second,
      inte2 = in_fr2.first, frac2 = in_fr2.second;
    BNI res = BNI(inte1 + frac1) * (inte2 + frac2);
    int deci = decimals + rhs.decimals;
    string res_s = res.c_str();
    while (res_s.size() < deci) res_s = '0' + res_s;
    return BNF(res_s.substr(0, res_s.size() - deci) + '.'
               + res_s.substr(res_s.size() - deci));
  }
  BNF& operator*=(const BNF &rhs) {
    return *this = *this * rhs;
  }
  bool operator<(const BNF &rhs) const {
    pair<string, string> in_fr1 = split(), in_fr2 = rhs.split();
    string inte1 = in_fr1.first, frac1 = in_fr1.second,
      inte2 = in_fr2.first, frac2 = in_fr2.second;
    if (inte1 < inte2) return true;
    else if (inte1 == inte2) return frac1 < frac2;
    else return false;
  }
  bool operator>(const BNF &rhs) const { return rhs < *this; }
  bool operator<=(const BNF &rhs) const { return !(*this > rhs); }
  bool operator>=(const BNF &rhs) const { return !(*this < rhs); }
  bool operator!=(const BNF &rhs) const { return (*this < rhs) || (*this > rhs); }
  bool operator==(const BNF &rhs) const { return !(*this != rhs); }

protected:
  int decimals = 0;
  LL sum_has_carry(const BNI &a, const BNI &b, BNI &sum) const {
    int max_len = max_(a.size(), b.size());
    sum = a + b;
    if (sum.size() > max_len) { sum.left_shift(); return 1LL; }
    return 0LL;
  }
  BNF join_inte_frac(const BNI &inte, const BNI &frac) const {
    return BNF(inte.c_str() + "." + frac.c_str());
  }
  string clean_tail_zero_str(const string &s) {
    int i = 0;
    string r;
    while (i < s.size() && '.' != s[i]) r += s[i++];

    int j = s.size() - 1;
    while (j >= 0 && '0' == s[j]) --j;
    for (int k = i + 1; k <= j; ++k) r += s[k];
    decimals = j >= i ? j - i : 0;
    return r;
  }
  string clean_zero_str(const string &s) {
    string r = BNI::clean_zero_str(s);
    return clean_tail_zero_str(r);
  }
  string c_str() const {
    string s;
    for (int i = 0; i < num.size(); ++i) {
      if (i == decimals) s = '.' + s;
      s = char(num[i] + '0') + s;
    }
    if (s.empty()) s = "0";
    if (num.size() == decimals) s = '.' + s;
    return s;
  }
  pair<string, string> split() const {
    string s = c_str();
    size_t p = s.find('.');
    return make_pair(s.substr(0, p), s.substr(p + 1));
  }
};

ostream &operator<<(ostream &out, const BNF &x) {
  cout << x.c_str(); return out;
}

istream &operator>>(istream &in, BNF &x) {
  x = BNF(in); return in;
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

double random_() {
  // generate random number in [0, 1]
  return double(rand()) / RAND_MAX;
}

int random_(int m) {
  // generate random int between [0, m - 1]
  return int(random_() * (m - 1) + 0.5);
}

// ==================================================


int direction[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1},
                        {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

const int MAXN = 150;
int mat[MAXN][MAXN], parent[MAXN][MAXN], dir[MAXN][MAXN], dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
int que[MAXN * MAXN];
int n, m;
char name[5] = "UDLR";

void bfs( int x, int y ) {
  int front = 0, rear = 0, u = x * m + y;
  que[rear++] = u; parent[x][y] = u; dist[x][y] = 0;

  while (front < rear) {
    int t = que[front++], tx = t / m, ty = t % m;
    vis[tx][ty] = true;
    REP(i, 4) {
      int nx = tx + direction[i][0], ny = ty + direction[i][1];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
          mat[nx][ny] && !vis[nx][ny]) {
        
        que[rear++] = nx * m + ny; parent[nx][ny] = t; dir[nx][ny] = i;
        dist[nx][ny] = dist[tx][ty] + 1;
      }
    }
  }
}

int path_dir_index[MAXN*MAXN];

void print_path(int x, int y) {
  int p, x1 = x, y1 {y}, cnt = 0;

  while (parent[x1][y1] != x1 * m + y1) {
    path_dir_index[cnt++] = dir[x1][y1];
    p = parent[x1][y1];
    x1 = p / m; y1 = p % m;
  }

  while (cnt--) {
    cout << name[path_dir_index[cnt]];
  } NL;
}

int main(void) {

  // 走迷宮
#ifdef DEBUG
  freopen("6-4-2.in", "r", stdin);
#endif

  while (cin>>n>>m) {
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    REP(i, n) {
      REP(j, m) cin >> mat[i][j];
    }
    int startx, starty, endx, endy;
    cin >> startx >> starty >> endx >> endy;
    bfs(startx, starty);
    print_path(endx, endy);
  }

  return 0;
}
