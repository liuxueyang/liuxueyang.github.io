// ==================================================

// C library
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

#define PRINT1(x) PR(x), NL
#define PRINT2(x1, x2) PR(x1), PRINT1(x2)
#define PRINT3(x1, x2, x3) PR(x1), PRINT2(x2, x3)
#define PRINT4(x1, x2, x3, x4) PR(x1), PRINT3(x2, x3, x4)

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

// print array
// TODO: use begin and end
template<typename T>
void PRA(const T ar[], int n) {
  for (int i = 0; i < n; ++i) PRC(ar[i]); NL;
}

// print pair
template<typename T1, typename T2>
void PRP(const pair<T1, T2>& p) { PRC(p.first); PRINTLN(p.second); }

// print a value and a new line
template<typename T>
void PRLN(const T& a) { cout << a << "\n"; }

// print a container, including a C-style array,
// but requires the first element to get element type
// TODO: Is it possible to remove the second argument?
template< typename T1, typename T2 >
void PRINTAV( T1 & vec, T2 x) {
  ostream_iterator< T2 > O( cout, " " );
  copy( begin( vec ), end( vec ), O ); NL;
}

// ==================================================


const int MAXN = 5000 + 20;
char buf[MAXN], s[MAXN], p[MAXN];

int main( void ) {

#ifdef DEBUG
  freopen("3-4_parli_substr.in", "r", stdin);
#endif

  int len = 0;
  
  while (NULL != fgets(buf, MAXN, stdin)) {
    REP(i, strlen(buf)) {
      if (isalpha(buf[i])) {
        p[len] = i;
        s[len++] = toupper(buf[i]);
      }
    }

    int start = 0, end = 0, res_len = 1;

    REP(i, len) {
      // odd length
      for (int j = 0; i - j >= 0 && i + j < len; j++) {
        if (s[i + j] != s[i - j]) break;
        if (j * 2 + 1 > res_len) {
          res_len = j * 2 + 1;
          start = p[i - j];
          end = p[i + j];
        }
      }

      // even length, take care of index to ensure start <= end
      for (int j = 0; i - j >= 0 && i + j + 1 < len; ++j) {
        if (s[i - j] != s[i + j + 1]) break;
        if (j * 2 + 2 > res_len) {
          res_len = j * 2 + 2;
          start = p[i - j];
          end = p[i + j + 1];
        }
      }
    }

    PRINT1(res_len);
    FOR_1(i, start, end) {
      printf("%c", buf[i]);
    } NL;
  }

  return 0;
}
