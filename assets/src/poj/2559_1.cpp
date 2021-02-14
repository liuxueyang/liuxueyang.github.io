#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100009;
LL h[N], l[N], r[N], stk[N];

int main() {
  #ifdef DEBUG
  freopen("2559.in", "r", stdin);
  #endif

  int n;
  while (~scanf("%d", &n) && n) {
    for (int i = 1; i <= n; ++i) scanf("%lld", h+i);
    h[n+1] = h[0] = -1;
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    LL res = 0;
    int tt = 0;

    stk[++tt] = 0;
    for (int i = 1; i <= n; ++i) {
      while (tt && h[stk[tt]] >= h[i]) {
        --tt;
      }
      l[i] = stk[tt];
      stk[++tt] = i;
    }

    tt = 0;
    stk[++tt] = n+1;
    for (int i = n; i >= 1; --i) {
      while (tt && h[stk[tt]] >= h[i]) {
        --tt;
      }
      r[i] = stk[tt];
      stk[++tt] = i;
    }

    for (int i = 1; i <= n; ++i) {
      res = max(res, (r[i] - l[i] - 1) * h[i]);
    }

    printf("%lld\n", res);
  }

  return 0;
}
