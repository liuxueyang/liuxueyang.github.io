#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000010;
typedef long long ll;
ll a[N], n, m;

int main() {
  #ifdef _DEBUG
  freopen("1873.in", "r", stdin);
  #endif

  scanf("%lld%lld", &n, &m);
  ll top = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
    top = max(top, a[i]);
  }

  ll l = 0, r = top, mid;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    ll sum = 0;

    for (int i = 0; i < n; ++i) {
      if (a[i] > mid) {
        sum += a[i] - mid;
      }
    }

    if (sum >= m) l = mid;
    else r = mid - 1;
  }
  printf("%lld\n", l);

  return 0;
}
