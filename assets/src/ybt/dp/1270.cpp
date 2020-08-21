// 1270.cpp --- 1270：【例9.14】混合背包
// 
// Filename: 1270.cpp
// Description: 
// Author: read eval print loop
// Maintainer: 
// Created: Fri Aug 21 22:52:42 2020 (+0800)
// Version: 
// Last-Updated: Fri Aug 21 23:07:25 2020 (+0800)
//           By: read eval print loop
//     Update #: 1
// URL: http://ybt.ssoier.cn:8088/problem_show.php?pid=1270
// Keywords: DP
// Compatibility: 
// 
// 

// Commentary: 
// 1A
// 多重背包使用二进制优化转化成01背包
// 转化成了完全背包和01背包
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


const int M = 500, N = 1000;
int m, n, d[M], w[N], c[N], p[N];

int main( void ) {

#ifdef DEBUG
  freopen("1270.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n;
  int n1 = n;
  for (int i = 1; i < n+1; ++i) {
    cin >> w[i] >> c[i] >> p[i];
    if (p[i] < 2) continue;
    // 二进制优化
    int cnt = p[i], cur = 2;
    p[i] = 1;
    cnt--;
    while (cnt > cur) {
      cnt -= cur;
      c[++n1] = cur * c[i];
      w[n1] = cur * w[i];
      p[n1] = 1;
      cur <<= 1;
    }
    if (cnt) {
      c[++n1] = cnt * c[i];
      w[n1] = cnt * w[i];
      p[n1] = 1;
    }
  }

  for (int i = 1; i < n1+1; ++i) {
    if (!p[i]) {
      for (int v = w[i]; v <= m; ++v) {
        d[v] = max_(d[v], d[v-w[i]] + c[i]);
      }

    } else {
      for (int v = m; v >= w[i]; --v) {
        d[v] = max_(d[v], d[v-w[i]] + c[i]);
      }

    }
  }

  cout << d[m] << "\n";

  return 0;
}


// 
// 1270.cpp ends here
