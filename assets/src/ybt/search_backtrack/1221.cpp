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


int gcd(int a,int b) {
  if (a < b) swap(a, b);
  if (a == b) return a;
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

bool check(int a, int b) {
  return gcd(a, b) == 1;
}

const int N = 20;
bool pr[N][N];
int a[N], n, b[N];
LL res, cnt;

void dfs(int pos) {
  if (pos == 0) {
    ++cnt;
    b[pos] = cnt;
    dfs(pos + 1);
    return;
  }
  if (pos == n) {
    res = min_(res, cnt);
    return;
  }
  if (cnt >= res) return;
  for (int i = 0; i < pos; ++i) {
    if (pr[i][pos] && b[i]) {
      b[pos] = b[i];
      dfs(pos + 1);
      b[pos] = 0;
    }
  }
  b[pos] = ++cnt;
  dfs(pos + 1);
}

int main( void ) {

#ifdef DEBUG
  freopen("1221.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      pr[i][j] = pr[j][i] = check(a[i], a[j]);
      // if (pr[i][j])
      //   PRINT2(i, j);
    }
  }

  res = oo;
  dfs(0);
  cout << res << endl;

  return 0;
}
