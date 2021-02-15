#include <algorithm>
#include <cstdio>

using namespace std;
using ll = long long;
const int N = 100010;
const ll INF = 1*1e10 + 10;
ll a[N], b[N];
ll m, n, k;

bool check(ll x, ll k) {
  ll cnt = 0;
  for (int i = 1; i <= n; ++i) {
    ll l = 1, r = m, mid;

    while (l < r) {
      mid = (l + r + 1) / 2;

      ll sum = a[i] + b[mid];
      if (sum <= x) l = mid;
      else r = mid - 1;
    }

    if (a[i] + b[l] <= x)
      cnt += l;
    if (cnt >= k)
      return true;
  }
  return false;
}

ll bsearch(ll l, ll r, ll k) {
  ll mid;
  while (l < r) {
    mid = (r + l) / 2;

    if (check(mid, k)) r = mid;
    else l = mid + 1;
  }

  return r;
}

int main() {
  #ifdef _DEBUG
  freopen("2020.in", "r", stdin);
  #endif

  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
  for (int i = 1; i <= m; ++i) scanf("%lld", b + i);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  printf("%lld\n", bsearch(1, INF, k));

  return 0;
}
