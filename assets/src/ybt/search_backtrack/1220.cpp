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
#define oo (1LL<<31);
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


const int N = 30;
int c[N], res, n;
string a[N], s;

void appS(string &a, string b, int k) {
  for (int i = k; i < int(b.size()); ++i) a += b[i];
}

void dfs(string x) {
  res = max_(res, int(x.size()));
  for (int i = 0; i < n; ++i) {
    if (c[i] >= 2) continue;
    int lena = int(x.size()), lenb = int(a[i].size()), len = min_(lena,lenb);
    // 不需要判断是否是前缀、后缀，如果出现前缀或者后缀，那么一定不是最长的
    for (int k = 1; k <= len; ++k) {
      bool flag = true;
      for (int j = 0; j < k; ++j) {
        if (a[i][j] != x[lena-k+j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        string x1 = x;
        ++c[i];
        appS(x1, a[i], k);
        dfs(x1);
        --c[i];
      }
    }
  }
}

int main( void ) {

#ifdef DEBUG
  freopen("1220.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> s;
  dfs(s);
  cout << res;
  NL;

  return 0;
}
