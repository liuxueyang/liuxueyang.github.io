// 1330.cpp --- 【例8.3】最少步数
//
// Filename: 1330.cpp
// Description:
// Author: abel-abel
// Maintainer:
// Created: 二  8月 11 23:33:34 2020 (+0800)
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


const int N = 120;
int a[N][N], M = 100;
const int di[12][2] = {
                       {2, 1}, {2, -1},
                       {-2, 1}, {-2, -1},
                       {1, 2}, {1, -2},
                       {-1, 2}, {-1, -2},
                       {2, 2}, {2, -2},
                       {-2, 2}, {-2, -2},
};

bool check(int x, int y) {
  return (x >= 1 && x <= 100 &&
          y >= 1 && y <= 100 && a[x][y] == -1);
}

int main( void ) {

#ifdef DEBUG
  freopen("1330.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;

  for (int i = 1; i <= M; ++i) {
    for (int j = 1; j <= M; ++j) {
      a[i][j] = -1;
    }
  }
  a[1][1] = 0;
  queue<PII> que;
  que.push(make_pair(1, 1));
  while (!que.empty()) {
    PII t = que.front();
    que.pop();
    int x = t.first, y = t.second, x1, y1;
    for (int k = 0; k < 12; ++k) {
      x1 = x + di[k][0];
      y1 = y + di[k][1];
      if (check(x1, y1)) {
        a[x1][y1] = a[x][y] + 1;
        que.push(make_pair(x1, y1));
      }
    }
  }
  cout << a[a1][a2] << "\n" << a[b1][b2] << endl;

  return 0;
}


//
// 1330.cpp ends here
