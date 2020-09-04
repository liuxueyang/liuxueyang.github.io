// readable.cpp --- Human readable duration format
// 
// Filename: readable.cpp
// Description: 
// Author: 刘雪杨
// Maintainer: 
// Created: Fri Sep  4 17:09:33 2020 (+0800)
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
// https://www.codewars.com/kata/52742f58faf5485cae000b9a
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


// Assert::That(format_duration(0), Equals("now"));
// Assert::That(format_duration(1), Equals("1 second"));       
// Assert::That(format_duration(62), Equals("1 minute and 2 seconds"));
// Assert::That(format_duration(120), Equals("2 minutes"));
// Assert::That(format_duration(3662), Equals("1 hour, 1 minute and 2 seconds"));
int second = 1,
  minute = 60,
  hour = minute * 60,
  day = hour * 24,
  year = 365 * day;

string cnames[100] = {"", "second", "minute", "hour", "day", "year",
  "seconds", "minutes", "hours", "days", "years"};
  
int bnums[100] = {0, second, minute, hour, day, year};

string con1(int a, int i) {
  if (a == 0) {
    return "";
  }
  // PRINT3(a, i, cnames[i]);
  string res = to_string(a) + " ";
  if (a == 1) {
    res += cnames[i];
  } else {
    res += cnames[i+5];
  }
  return res;
}

std::string format_duration(int seconds) {
  string res;
  int a[100] = {0};
  int cntz = 0;

  for (int i = 5; i >= 1; --i) {
    a[i] = seconds / bnums[i];
    // PRINT3(i, cnames[i], a[i]);
    if (a[i]) cntz++;
    seconds %= bnums[i];
  }

  if (!cntz) {
    res = "now";
  } else if (cntz == 1) {
    for (int i = 5; i >= 1; --i) {
      if (a[i]) {
        res = con1(a[i], i);
        break;
      }
    }
  } else {
    for (int i = 5; i >= 1; --i) {
      if (a[i]) {
        if (cntz >= 3) {
          res += con1(a[i], i) + ", ";
        } else if (cntz >= 2) {
          res += con1(a[i], i) + " and ";
        } else {
          res += con1(a[i], i);
        }
        cntz--;
      }
    }

  }
  
  return res;
}

int main( void ) {

#ifdef DEBUG
  freopen("readable.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    PRINT1(n);
    cout << format_duration(n) << "\n";

  }

  return 0;
}


// 
// readable.cpp ends here
