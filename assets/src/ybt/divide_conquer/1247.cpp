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


const int N = 50000+10;
int a[N],b[N],l,n,m;

int rcnt(int len) {
  for (int i = 0; i <= n; ++i) {
    b[i] = a[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i] - b[i-1] < len) {
      b[i] = b[i-1];
      ++cnt;
      if (cnt > m) {
        return cnt;
      }
    }
  }
  return cnt;
}

int main( void ) {

#ifdef DEBUG
  freopen("1247.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> l >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  a[0] = 0;
  a[++n] = l;
  sort(a, a+1+n);
  int low = 1, high = l, cnt;
  while (low < high-1) {
    int mid = (low + high) >> 1;
    cnt = rcnt(mid);
    if (cnt > m) {
      high = mid;
    }
    else {
      low = mid;
    }
  }
  cnt = rcnt(high);
  if (cnt <= m) {
    cout << high << "\n";
    return 0;
  }
  cout << low << "\n";

  return 0;
}
