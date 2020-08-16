// 1266.cpp --- 1266：【例9.10】机器分配
//
// Filename: 1266.cpp
// Description:
// Author: read eval print loop
// Maintainer:
// Created: Sun Aug 16 22:26:53 2020 (+0800)
// Version:
// Last-Updated: Sun Aug 16 23:20:23 2020 (+0800)
//           By: read eval print loop
//     Update #: 1
// URL:
// Keywords:
// Compatibility:
//
//

// Commentary:
// 4WA
// 这题神坑。题目描述并没有写字典序最小，调试半天，最后在网上找到了这个条件。
// https://blog.csdn.net/weixin_44574520/article/details/89603929
//
// 计算的过程中记录路径即可：path[i][j]表示第j个城市使用的机器个数。

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


const int N = 20;
LL d[N][N], n, m, path[N][N], a[N][N];

void print_path(int i, int j) {
  if (!i) {
    return;
  }
  LL w = path[i][j];
  print_path(i-1, j-w);
  cout << i << " " << w << "\n";
}

int main( void ) {

#ifdef DEBUG
  freopen("1266.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int w = 0;
      for (int k = 0; k <= j; ++k) {
        int t = d[i-1][k] + a[i][j-k];
        if (d[i][j] < t) {
          w = k;
          d[i][j] = t;
        }
      }

      path[i][j] = j-w;
    }

  }
  cout << d[n][m] << "\n";
  print_path(n, m);


  return 0;
}


//
// 1266.cpp ends here
