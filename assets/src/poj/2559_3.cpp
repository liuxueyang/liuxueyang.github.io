#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
const int N = 100010;
int n, a[N], l[N], r[N], s[N];

int main() {
#ifdef _DEBUG
  freopen("2559.in", "r", stdin);
#endif

  while (scanf("%d", &n)) {
    if (!n) break;

    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    a[0] = a[n+1] = -1;

    memset(s, 0, sizeof s);

    int st = 0;
    s[++st] = 0;
    for (int i = 1; i <= n; ++i) {
      while (st && a[s[st]] >= a[i]) {
        --st;
      }
      l[i] = s[st];
      s[++st] = i;
    }

    st = 0;
    s[++st] = n + 1;
    for (int i = n; i >= 1; --i) {
      while (st && a[s[st]] >= a[i]) --st;
      r[i] = s[st];
      s[++st] = i;
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      res = max(res, ll(r[i] - l[i] - 1) * a[i]);
    }
    printf("%lld\n", res);
  }

  return 0;
}
