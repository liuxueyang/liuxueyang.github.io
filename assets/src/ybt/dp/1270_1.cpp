// 1270_1.cpp ---
//
// Filename: 1270_1.cpp
// Description:
// Author: 刘雪杨
// Maintainer:
// Created: Tue Jan  5 13:58:53 2021 (+0800)
// Version:
// Last-Updated:
//           By:
//     Update #: 0
// URL:
// Keywords:
// Compatibility:
//
//

// Commentary:
//
//
//
//

// Change Log:
//
//
//
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; see the file COPYING.  If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth
// Floor, Boston, MA 02110-1301, USA.
//
//

// Code:

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

// Input/Output
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <ios>
#include <iomanip>

// Other
#include <string>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iterator>
#include <limits>

// ==================================================

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

// ==================================================

__attribute__((unused)) const static int dir[8][2] = {
  {0, 1}, {1, 0},
  {0, -1},{-1, 0},
  {1, 1}, {1, -1},
  {-1,1}, {-1,-1},
};

// ==================================================
#define oo (1LL<<31)
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


const int M = 233, N = 30*6+10;
int d[M], w[N], v[N], tmp, m, n, com[N];

int main( void ) {

#ifdef DEBUG
  freopen("1270.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n;
  int len = 0;

  // complete bag
  memset(com, 0, sizeof com);

  for (int i = 0; i < n; ++i) {
    int w1, c1, p1;
    cin >> w1 >> c1 >> p1;
    if (p1 == 1) {
      w[len] = w1;
      v[len] = c1;
      ++len;
    } else if (p1 == 0) {
      w[len] = w1;
      v[len] = c1;
      com[len] = 1;
      ++len;
    } else {
      int tmp = 1;
      while (p1 > 0) {
        if (p1 > tmp) {
          w[len] = tmp * w1;
          v[len] = tmp * c1;
        } else {
          w[len] = p1 * w1;
          v[len] = p1 * c1;
        }
        p1 -= tmp;
        tmp *= 2;
        ++len;
      }
    }
  }
  memset(d, 0, sizeof d);
  for (int i = 0; i < len; ++i) {
    if (com[i]) {
      // complete
      for (int W = w[i]; W <= m; ++W) {
        if (d[W] < d[W-w[i]] + v[i]) {
          d[W] = d[W-w[i]] + v[i];
        }
      }
    } else {
      for (int W = m; W >= w[i]; --W) {
        if (d[W] < d[W-w[i]] + v[i]) {
          d[W] = d[W-w[i]] + v[i];
        }
      }
    }
  }
  cout << d[m] << endl;

  return 0;
}


//
// 1270_1.cpp ends here
