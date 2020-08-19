// 1269.cpp --- 1269：【例9.13】庆功会
// 
// Filename: 1269.cpp
// Description: 
// Author: read eval print loop
// Maintainer: 
// Created: Wed Aug 19 23:11:05 2020 (+0800)
// Version: 
// Last-Updated: Thu Aug 20 00:09:17 2020 (+0800)
//           By: read eval print loop
//     Update #: 1
// URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 4WA
// 原来输入里面有个数为0的呀。想了半天没想明白哪里错了。
// 此时把个数为0的花费和价值都设置成0就可以了。
// 不可以--i，显然会循环啊。T_T

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


const int N = 10000, M = 10000;
int n, m, w[N], c[N], s[N], d[M];

int main( void ) {

#ifdef DEBUG
  freopen("1269.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  int n1 = n;
  for (int i = 1; i < n+1; ++i) {
    cin >> w[i] >> c[i] >> s[i];
    if (s[i] == 0) {
      w[i] = c[i] = 0;
      continue;
    }
    if (s[i] > 1) {
      int cur = 2;
      --s[i];
      while (s[i] >= cur) {
        s[i] -= cur;
        w[++n1] = cur * w[i];
        c[n1] = cur * c[i];
        cur <<= 1;
      }
      if (s[i]) {
        w[++n1] = s[i] * w[i];
        c[n1] = s[i] * c[i];
      }
    }
  }
  
  for (int i = 1; i < n1+1; ++i) {
    for (int v = m; v >= w[i]; --v) {
      d[v] = max_(d[v], d[v-w[i]] + c[i]);
    }

  }
  
  cout << d[m] << "\n";

  return 0;
}


// 
// 1269.cpp ends here
