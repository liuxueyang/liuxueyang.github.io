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

    memset(s, 0, sizeof s);

    int st = 0;
    s[++st] = 1;
    l[1] = 0;
    for (int i = 2; i <= n; ++i) {
      while (st && a[s[st]] >= a[i]) {
        --st;
      }
      l[i] = s[st];
      s[++st] = i;
    }

    st = 0;
    s[++st] = n;
    r[n] = n + 1;
    for (int i = n - 1; i >= 1; --i) {
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
