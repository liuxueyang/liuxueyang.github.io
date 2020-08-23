// 1271.cpp --- 1271：【例9.15】潜水员
// 
// Filename: 1271.cpp
// Description: 
// Author: abel-abel
// Maintainer: 
// Created: 日  8 23 13:47:37 2020 (+0800)
// Version: 
// Last-Updated: 日  8 23 14:17:30 2020 (+0800)
//           By: 刘雪杨
//     Update #: 1
// URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 2WA
// 其实还不是很理解
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


const int M = 30*3, N = 100*3, K = 1234;
LL d[M][N], a[K], b[K], w[K], m, n, k;

int main( void ) {

#ifdef DEBUG
  freopen("1271.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n >> k;
  for (int i = 1; i < k+1; ++i) {
    cin >> a[i] >> b[i] >> w[i];
  }

  for (int i = 0; i < m*2+1; ++i) {
    for (int j = 0; j < n*2+1; ++j) {
      d[i][j] = oo;
    }

  }

  d[0][0] = 0;
  for (int i = 1; i < k+1; ++i) {
    for (int j = m*2; j >= a[i]; --j) {
      for (int z = n*2; z >= b[i]; --z) {
        if (d[j-a[i]][z-b[i]] != oo) {
          int j1 = min_(j, m), z1 = min_(z, n);
          d[j1][z1] = min_(d[j1][z1], d[j-a[i]][z-b[i]] + w[i]);
        }
      }

    }

  }

  cout << d[m][n] << "\n";

  return 0;
}


// 
// 1271.cpp ends here
