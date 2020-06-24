// ==================================================

// C library
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using PII = pair<int, int>;

// ==================================================

static auto __________2333__________ = []() {
                                         ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

// ==================================================
#define max_(x, y) ((x) > (y) ? (x) : (y))
#define min_(x, y) ((x) > (y) ? (y) : (x))

#define PR(x) cout << #x " = " << (x) << "\t"
#define NL cout << "\n"

#define PRINT1(x) PR(x), NL
#define PRINT2(x1, x2) PR(x1), PRINT1(x2)
#define PRINT3(x1, x2, x3) PR(x1), PRINT2(x2, x3)
#define PRINT4(x1, x2, x3, x4) PR(x1), PRINT3(x2, x3, x4)

// ==================================================

template<typename T>
void PRINTC(const T& a) { cout << a << " "; }

template<typename T>
void PRINT_CONTAINER(const T& c) { for (auto x : c) PRINTC(x); NL; }

template<typename T>
void PRINTV(const vector<T>& c) { PRINT_CONTAINER<vector<T>>(c); }

template<typename T>
void PRINTA(const T ar[], int n) {
  for (int i = 0; i < n; ++i) PRINTC(ar[i]); NL;
}

template<typename T1, typename T2>
void PRINTP(const pair<T1, T2>& p) { PRINTC(p.first); PRINTLN(p.second); }

template<typename T>
void PRINTLN(const T& a) { cout << a << "\n"; }

template< typename T1, typename T2 >
void PRINTAV( T1 & vec, T2 x) {
  ostream_iterator< T2 > O( cout, " " );
  copy( begin( vec ), end( vec ), O ); NL;
}

// ==================================================


using LL = long long int;
const int N = 10000;
const LL oo = 0xfffffff0;

LL d[N][5][5], a[N];

int ef(int x, int y) {
  if (x+y==0) return 0;
  if (x==y) return 1;
  if (x==0 || y==0) return 2;
  if (abs(x-y) == 2) return 4;
  return 3;
}

int main( void ) {

#ifdef DEBUG
  freopen("uva1291.in", "r", stdin);
#endif

  int a0, n;
  while (cin >> a0 && a0) {
    int i = 1;
    a[i] = a0;
    while (cin >> a0 && a0) {
      a[++i] = a0;
    }
    n = i;

    d[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 4; j++)
        for (int k = 0; k <= 4; k++)
          d[i][j][k] = oo;
    }
    for (int k = 1; k <= n; k++) {
      if (k == 1) {
        d[k][a[k]][0] = d[k][0][a[k]] = ef(0, a[k]);
        continue;
      }
      for (int l = 0; l <= 4; l++) {
        for (int r = 0; r <= 4; r++) {
          LL &res = d[k][l][r];
          if (l == a[k] && r != l) {
            for (int l1 = 0; l1 <= 4; l1++) {
              res = min_(d[k-1][l1][r] + ef(l1, a[k]), res);
            }
          }
          else if (r == a[k] && l != r) {
            for (int r1 = 0; r1 <= 4; r1++) {
              res = min_(d[k-1][l][r1] + ef(r1, r), res);
            }
          }
        }
      }
    }
    LL res = oo;
    for (int l = 0; l <= 4; l++)
      for (int r = 0; r <= 4; r++)
        res = min_(res, d[n][l][r]);
    cout << res << endl;
  }

  return 0;
}
