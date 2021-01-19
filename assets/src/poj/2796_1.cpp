#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long LL;
const int N = 100009;
LL a[N], pre[N], l[N], r[N], stk[N];

int main() {
  #ifdef DEBUG
  freopen("2796.in", "r", stdin);
  #endif

  int n;
  while (~scanf("%d", &n)) {
    memset(pre, 0, sizeof pre);
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a+i);
      pre[i] = a[i] + pre[i-1];
    }

    int left = -1, right = -1;
    LL res = -1;
    int tt = 0;
    
    a[0] = a[n+1] = -1;
    stk[++tt] = 0;
    
    for (int i = 1; i <= n; ++i) {
      while (tt && a[stk[tt]] >= a[i]) {
        --tt;
      }
      l[i] = stk[tt];
      stk[++tt] = i;
    }

    tt = 0;
    stk[++tt] = n+1;
    for (int i = n; i >= 1; --i) {
      while (tt && a[stk[tt]] >= a[i]) {
        --tt;
      }
      r[i] = stk[tt];
      stk[++tt] = i;
    }
    
    for (int i = 1; i <= n; ++i) {
      LL ires = (pre[r[i] - 1] - pre[l[i]]) * a[i];
      if (ires > res) {
        res = ires;
        left = l[i] + 1;
        right = r[i] - 1;
      }
    }
    printf("%lld\n%d %d\n", res, left, right);
  }
  
  return 0;
}
