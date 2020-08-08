// ==================================================

// C library
#include <cstdio>
#include <cstdlib>

// Input/Output
#include <iostream>

// ==================================================

using namespace std;

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

// ==================================================


const int N = 200000 + 100;
int a[N], n;

void qso(int l, int r) {
  if (l >= r) return;
  int mid = a[(l+r)>>1], i = l, j = r;
  while (i <= j) {
    while (a[i] < mid) {
      ++i;
    }
    while (a[j] > mid) {
      --j;
    }
    if (i <= j) {
      swap(a[i], a[j]);
      ++i;
      --j;
    }
  }
  if (i < r) qso(i, r);
  if (j > l) qso(l, j);
}

int main( void ) {

#ifdef DEBUG
  freopen("1239.in", "r", stdin);
#endif

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i+1];
  }
  qso(1, n);
  int s = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i] == a[i-1]) {
      ++s;
      continue;
    }
    else {
      cout << a[i-1] << " " << s << "\n";
      s = 1;
    }
  }
  cout << a[n] << " " << s << "\n";

  return 0;
}
