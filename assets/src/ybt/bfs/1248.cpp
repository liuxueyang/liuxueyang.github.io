// 1248.cpp --- 1248：Dungeon Master
// 
// Filename: 1248.cpp
// Description: 
// Author: abel-abel
// Maintainer: 
// Created: 二  8月 11 23:58:02 2020 (+0800)
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


const int N = 100+10;
bool vis[N][N][N];
int a[N][N][N], z, n, m;
char g[N][N][N];

struct Point {
  int z, x, y;
};

const int di[6][3] = {
                      {0, 1, 0}, {0, 0, 1},
                      {0, -1, 0}, {0, 0, -1},
                      {1, 0, 0}, {-1, 0, 0},
};

bool check(int z1, int x1, int y1) {
  return (z1 >= 0 && z1 < z &&
          x1 >= 0 && x1 < n &&
          y1 >= 0 && y1 < m &&
          !vis[z1][x1][y1]);
}

int main( void ) {

#ifdef DEBUG
  freopen("1248.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> z >> n >> m) {
    if (z+n+m == 0) {
      break;
    }
    Point start, end;
    for (int i = 0; i < z; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
        for (int k = 0; k < m; ++k) {
          a[i][j][k] = -1;
          if (g[i][j][k] == 'S') {
            start = Point{i,j,k};
            vis[i][j][k] = false;
            a[i][j][k] = 0;
          } else if (g[i][j][k] == 'E') {
            end = Point{i,j,k};
            vis[i][j][k] = false;
          } else if (g[i][j][k] == '#') {
            vis[i][j][k] = true;
          } else {
            vis[i][j][k] = false;
          }
        }
      }
    }
    queue<Point> que;
    que.push(start);
    int res = -1;
    
    while (!que.empty()) {
      Point t = que.front();
      int z1 = t.z, x1 = t.x, y1 = t.y;
      int ori = a[z1][x1][y1];
      vis[z1][x1][y1] = true;
      
      que.pop();
      for (int i = 0; i < 6; ++i) {
        int z2, x2, y2;
        z2 = z1+di[i][0];
        x2 = x1+di[i][1];
        y2 = y1+di[i][2];
        if (check(z2, x2, y2)) {
          Point t1 = Point{z2, x2, y2};
          
          if (x2 == end.x && y2 == end.y && z2 == end.z) {
            res = ori + 1;
            break;
          }
          que.push(t1);
          a[z2][x2][y2] = ori + 1;
        }
      }
    }
    if (res == -1) {
      cout << "Trapped!" << "\n";
    } else {
      cout << "Escaped in " << res << " minute(s)." << "\n";
    }
  }
 

  return 0;
}


// 
// 1248.cpp ends here
