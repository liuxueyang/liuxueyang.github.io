#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 100010;
int a[N], l[N], r[N], stk[N], n;

int main() {
  #ifdef _DEBUG
  freopen("2559.in", "r", stdin);
  #endif

  while (~scanf("%d", &n) && n) {
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    a[0] = a[n + 1] = -1;

    int tt = 0;
    stk[++tt] = 0;
    for (int i = 1; i <= n; ++i) {
      while (a[stk[tt]] >= a[i]) --tt;
      l[i] = stk[tt];
      stk[++tt] = i;
    }

    tt = 0;
    stk[++tt] = n + 1;
    for (int i = n; i >= 1; --i) {
      while (a[stk[tt]] >= a[i]) --tt;
      r[i] = stk[tt];
      stk[++tt] = i;
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      res = max(res, ll(r[i] - l[i] - 1) * a[i]);
    }
    printf("%lld\n", res);
  }

  return 0;
}
