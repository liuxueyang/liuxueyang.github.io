#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 100010;
typedef long long ll;
ll a[N], n, k;

int main() {
  #ifdef _DEBUG
  freopen("2440.in", "r", stdin);
  #endif
  scanf("%lld%lld", &n, &k);
  ll top = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
    top = max(top, a[i]);
  }
  ll l = 0, r = top, mid;
  ll sum = 0;
  while (l < r) {
    sum = 0;
    mid = (l + r + 1) >> 1;
    if (mid == 0) {
      sum = 0;
      break;
    }
    for (int i = 0; i < n; ++i) sum += a[i] / mid;

    if (sum >= k) l = mid;
    else r = mid - 1;
  }
  if (l != 0) {
    sum = 0;
    for (int i = 0; i < n; ++i)
      sum += a[i] / l;

    if (sum >= k)
      printf("%lld\n", l);
    else
      printf("0\n");
  } else printf("0\n");

  return 0;
}
