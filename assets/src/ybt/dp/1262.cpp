// 1262.cpp --- 1262：【例9.6】挖地雷
// 
// Filename: 1262.cpp
// Description: 
// Author: read eval print loop
// Maintainer: 
// Created: Sat Aug 15 21:31:51 2020 (+0800)
// Version: 
// Last-Updated: Sat Aug 15 22:01:58 2020 (+0800)
//           By: read eval print loop
//     Update #: 1
// URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 1WA
// 考虑一种情况：只挖一个地窖，得到最终的最大值。
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


const int N = 233;
int n, a[N], d[N], path[N], g[N][N];

int main( void ) {

#ifdef DEBUG
  freopen("1262.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int x1, x2, pos, res = 0;
  cin >> n;
  for (int i = 1; i < n + 1; ++i) {
    cin >> a[i];
    path[i] = i;
    d[i] = a[i];
  }
  while (cin >> x1 >> x2) {
    if (x1 + x2 == 0) {
      break;
    }
    g[x1][x2] = 1;
  }
  
  for (int i = n-1; i >= 1; --i) {
    for (int j = i+1; j <= n; ++j) {
      if (g[i][j] && d[i] < d[j] + a[i]) {
        d[i] = d[j] + a[i];
        path[i] = j;
      }
    }
  }
  
  pos = 1;
  res = d[pos];
  for (int i = 2; i < n + 1; ++i) {
    if (d[i] > res) {
      res = d[i];
      pos = i;
    }
  }
  
  int rpo = pos;
  cout << rpo;
  while (rpo != path[rpo]) {
    rpo = path[rpo];
    cout << "-" << rpo;
  }
  NL;
  cout << res << "\n";

  return 0;
}


// 
// 1262.cpp ends here
