// 4-view-cn.cpp --- 
// 
// Filename: 4-view-cn.cpp
// Description: 
// Author: 刘雪杨
// Maintainer: 
// Created: Sun Nov  8 18:55:25 2020 (+0800)
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


class Solution {
public:
  bool findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return false;
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0) {
      if (matrix[i][j] > target) --j;
      else if (matrix[i][j] == target) return true;
      else ++i;
    }
    return false;
  }
  
  int binary_search(vector<vector<int> > &matrix, int row, int col, int target) {
    int low = 0, high, mid;
    if (row) high = int(matrix[0].size());
    else { high = int(matrix.size()); }
    while (high - low > 1) {
      mid = (low + high) / 2;
      if (row) {
        if (matrix[0][mid] <= target) low = mid;
        else high = mid;
      } else {
        if (matrix[mid][col] <= target) low = mid;
        else high = mid;
      }
    }
    
    if (row) {
      if (matrix[0][low] <= target) return low;
      else return -1;
    } else {
      PRINT2(low, matrix[low][col]);
      if (matrix[low][col] <= target) return low;
      else return -1;
    }
  }
};

int main( void ) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  vector<vector<int> > ma = {
    vector<int>{1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
  };
  vector<VI> mb {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}};
  Solution a;
  a.findNumberIn2DArray(mb, 19);

  return 0;
}


// 
// 4-view-cn.cpp ends here
