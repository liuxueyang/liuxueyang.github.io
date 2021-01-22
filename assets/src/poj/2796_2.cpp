#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 100010;
typedef long long ll;
int stk[N], n, a[N], l[N], r[N];
ll p[N];

int main() {
#ifdef DEBUG
  freopen("2796.in", "r", stdin);
#endif

  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);

    memset(p, 0, sizeof p);
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    for (int i = 1; i <= n; ++i)
      p[i] = p[i - 1] + a[i];

    a[0] = a[n + 1] = -1;

    int tt;
    tt = 1;
    stk[tt] = 0;

    for (int i = 1; i <= n; ++i) {
      while (tt && a[stk[tt]] >= a[i])
        --tt;
      l[i] = stk[tt];
      stk[++tt] = i;
    }

    tt = 1;
    stk[tt] = n + 1;

    for (int i = n; i >= 1; --i) {
      while (tt && a[stk[tt]] >= a[i])
        --tt;
      r[i] = stk[tt];
      stk[++tt] = i;
    }

    ll res = -1, posl = 0, posr = 0;
    for (int i = 1; i <= n; ++i) {
      ll tmp = (p[r[i] - 1] - p[l[i]]) * a[i];
      if (tmp > res) {
        res = tmp;
        posl = l[i] + 1;
        posr = r[i] - 1;
      }
    }

    printf("%lld\n%lld %lld\n", res, posl, posr);
  }

  return 0;
}
