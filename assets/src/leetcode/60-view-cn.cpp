// 60-view-cn.cpp --- 
// 
// Filename: 60-view-cn.cpp
// Description: 
// Author: 刘雪杨
// Maintainer: 
// Created: Sun Nov  8 17:56:10 2020 (+0800)
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
// d[n, k] 代表 n 个骰子和为 k 的可能性。而这可以有 n-1 个骰子推出来。
// d[n, k] = d[n-1, k-1] + d[n-1, k-2] + ...
// 
// 进而可以优化成一维数组

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


class Solution {
public:
    vector<double> dicesProbability(int n) {
      double d[100];
      memset(d, 0, sizeof d);
      for (int i = 1; i <= 6; ++i) d[i] = 1;
      for (int i = 2; i <= n; ++i) {
        for (int j = i*6; j >= i; --j) {
          double tmp = 0;       // :NOTE:
          for (int k = 1; k < j & k <= 6; ++k) {
            tmp += d[j-k];
          }
          d[j] = tmp;
        }
        for (int j = 1; j < i; ++j) d[j] = 0;
      }
      vector<double> res;
      double sum = 0;
      for (int i = n; i <= n*6; ++i) sum += d[i];
      for (int i = n; i <= n*6; ++i) {
        res.push_back(d[i]/sum);
      }
      return res;
    }
};

// int main(int argc, char *argv[])
// {
//   Solution a;
//   a.dicesProbability(2);
  
//   return 0;
// }


// 
// 60-view-cn.cpp ends here
