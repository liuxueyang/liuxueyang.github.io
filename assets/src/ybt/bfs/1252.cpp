// 1252.cpp --- 1252：走迷宫
// 
// Filename: 1252.cpp
// Description: 
// Author: read eval print loop
// Maintainer: 
// Created: Sat Aug 15 10:07:03 2020 (+0800)
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
// 过于简单，以至于好几个地方打错了。T_T 越是简单的题目越是要认真写。
// 3WA
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


const int N = 100;
bool vis[N][N];
int m, n, b[N][N];
char a[N][N];

bool check(int x, int y) {
  return (x >= 0 && x < m &&
          y >= 0 && y < n &&
          !vis[x][y] &&
          a[x][y] != '#');
}

int main( void ) {

#ifdef DEBUG
  freopen("1252.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  queue<PII> que;
  que.push(make_pair(0, 0));
  vis[0][0] = true;
  
  bool flag = false;
  
  while (!que.empty()) {
    PII t = que.front();
    que.pop();
    int x = t.first, y = t.second, x1, y1;
    
    for (int i = 0; i < 4; ++i) {
      x1 = x + dir[i][0];
      y1 = y + dir[i][1];
      
      if (check(x1, y1)) {
        if (x1 == m-1 && y1==n-1) {
          cout << b[x][y] + 2 << "\n";
          flag = true;
          break;
        }
        
        vis[x1][y1] = true;
        b[x1][y1] = b[x][y] + 1;
        que.push(make_pair(x1, y1));
      }
    }

    if (flag) {
      break;
    }
  }

  return 0;
}


// 
// 1252.cpp ends here
