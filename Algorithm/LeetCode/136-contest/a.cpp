// ==================================================

// C library
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Containers
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Input/Output
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

// Other
#include <algorithm>
#include <bitset>
#include <chrono>
#include <iterator>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <tuple>
#include <tuple>
#include <type_traits>
#include <utility>

// ==================================================

using namespace std;

// constants
const double EPS = 1e-9;
const int MOD = 1000000007;

// type alias
using PII = pair<int, int>;
using LL = long long int;
using VI = vector<int>;
using VC = vector<char>;
using VS = vector<string>;
using VVI = vector<VI>;
using MII = map<int, int>;
using MCI = map<char, int>;
using SI = set<int>;
using UMII = unordered_map<int, int>;
using USI = unordered_set<int>;

typedef struct TreeNode TreeNode;
using ptn = TreeNode *;
using tn = TreeNode;

// ==================================================

// fast IO
static auto __2333__ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ==================================================

// some macro for less typing
#define max_(x, y) ((x) > (y) ? (x) : (y))
#define min_(x, y) ((x) > (y) ? (y) : (x))

#define MK make_pair

#define REP(i, n) for (int i = 0; i < int(n); ++i)         // [0, n)
#define REPV(i, n) for (int i = int(n - 1); i >= 0; --i)   // reverse [0, n)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i) // [a, b)
#define DWN(i, b, a)                                                           \
  for (int i = int(b - 1); i >= int(a); --i) // reverse [a, b)

#define REP_1(i, n) for (int i = 1; i <= int(n); ++i)         // [1, n]
#define REPV_1(i, n) for (int i = int(n); i >= 1; --i)        // reverse [1, n]
#define FOR_1(i, a, b) for (int i = int(a); i <= int(b); ++i) // [a, b]
#define DWN_1(i, b, a) for (int i = int(b); i >= a; --i)      // reverse [a, b]

// DEBUG PRINT macro
#define P(x) cerr << (x)
#define NLL cerr << endl
#define PR(x) cerr << #x " = " << (x) << "\t"

#define NL cout << "\n"

#define PR1(x) PR(x), NLL
#define PR2(x1, x2) PR(x1), PR1(x2)
#define PR3(x1, x2, x3) PR(x1), PR2(x2, x3)
#define PR4(x1, x2, x3, x4) PR(x1), PR3(x2, x3, x4)

int direction[8][2] = {{-1, 0},  {0, -1}, {1, 0},  {0, 1},
                       {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

// ==================================================

// simplest print
template <typename T> void PRC(const T &a) { cout << a << " "; }

// print container
template <typename T> void PRCO(const T &c) {
  for (auto x : c)
    PRC(x);
  NL;
}

// print vector
template <typename T> void PRV(const vector<T> &c) { PRCO<vector<T>>(c); }

// print C-style array
template <typename T, size_t N> void PRA(const T (&ar)[N]) {
  for (auto x : ar)
    PRC(x);
  NL;
}

// print pair
template <typename T1, typename T2> void PRP(const pair<T1, T2> &p) {
  PRC(p.first);
  PRLN(p.second);
}

// print a value and a new line
template <typename T> void PRLN(const T &a) { cout << a << "\n"; }

// ==================================================
// math
bool is_prime(LL x) {
  if (x == 1 || x <= 0)
    return false;
  if (x == 2)
    return true;
  assert(x > 1);
  LL m = ceil(sqrt(x));
  FOR_1(i, 2, m) {
    if (!(x % i))
      return false;
  }
  return true;
}

// prime table
const int PRIME_MAX = 10;
VI prime_table;
vector<bool> prime_table_bool(PRIME_MAX, true);

void get_prime() {
  FOR_1(i, 2, PRIME_MAX) {
    if (prime_table_bool[i]) {
      prime_table.push_back(i);
      for (int j = i << 1; j <= PRIME_MAX; j += i)
        prime_table_bool[j] = false;
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

class Solution {
public:
  bool isRobotBounded(string instructions) {
    PII start(0, 0), cur(0, 0);
    int dir = 0, cnt = 0;
    for (int i = 0; i < instructions.size(); ++i) {
      if (instructions[i] == 'G') {
        cur.first += direction[dir][0];
        cur.second += direction[dir][1];
      } else if (instructions[i] == 'L') {
        dir = (dir + 1) % 4;
      } else if (instructions[i] == 'R') {
        dir = (dir + 4 - 1) % 4;
      }

      if (i == instructions.size() - 1) {
        i = -1;
        cnt++;
        if (start == cur)
          return true;
        if (cnt > 10)
          break;
      }
    }
    return cur == start;
  }
};

int main(void) {

#ifdef DEBUG
  freopen("a.in", "r", stdin);
#endif

  Solution a;
  string s;
  while (cin >> s) {
    PRLN(a.isRobotBounded(s));
  }

  return 0;
}
