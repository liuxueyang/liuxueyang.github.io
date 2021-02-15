#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 100010;
ll a[N], b[N], c[N];
int n, m, p[N];
ll d[N];

int main() {
  #ifdef _DEBUG
  freopen("3406.in", "r", stdin);
  #endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d", p + i);
  for (int i = 1; i < n; ++i) scanf("%lld%lld%lld", a + i, b + i, c + i);
  for (int i = 1; i < m; ++i) {
    int x = p[i], y = p[i + 1];
    if (x > y) swap(x, y);
    d[x] += 1;
    d[y] -= 1;
  }
  ll res = 0;
  for (int i = 1; i < n; ++i) {
    d[i] += d[i-1];
    ll x = d[i] * a[i], y = d[i] * b[i] + c[i];
    res += min(x, y);
  }
  printf("%lld\n", res);

  return 0;
}
