// 1250.cpp --- 1250：The Castle
// 
// Filename: 1250.cpp
// Description: 
// Author: read eval print loop
// Maintainer: 
// Created: Sat Aug 15 10:37:11 2020 (+0800)
// Version: 
// Last-Updated: Sat Aug 15 11:07:45 2020 (+0800)
//           By: read eval print loop
//     Update #: 1
// URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 1A
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


const int N = 60;
bool vis[N][N];
int a[N][N], m, n;

bool check(int x, int y) {
  return (x >= 0 && x < m &&
          y >= 0 && y < n &&
          !vis[x][y]);
}

int mask[4][2] = {
  {4, 1}, {8, 2},
  {1, 4}, {2, 8},
};

int main( void ) {

#ifdef DEBUG
  freopen("1250.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  int cnt = 0, maxr = 0, cur = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!vis[i][j]) {
        ++cnt;
        cur = 1;
        
        queue<PII> que;
        vis[i][j] = true;
        que.push(make_pair(i, j));
        
        while (!que.empty()) {
          PII t = que.front();
          que.pop();
          int x = t.first, y = t.second, x1, y1;
          
          for (int i = 0; i < 4; ++i) {
            x1 = x + dir[i][0];
            y1 = y + dir[i][1];
            
            if (check(x1, y1) &&
                ((a[x][y] & mask[i][0]) == 0 &&
                 (a[x1][y1] & mask[i][1]) == 0)) {
              vis[x1][y1] = true;
              que.push(make_pair(x1, y1));
              ++cur;
            }
          }

        }
        
        maxr = max_(maxr, cur);
      }
    }
  }
  
  cout << cnt << "\n" << maxr << endl;

  return 0;
}


// 
// 1250.cpp ends here
