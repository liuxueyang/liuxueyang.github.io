#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 200010;
int n, c, a[N];
typedef long long ll;

int bin_search(int l, int r, ll x) {
  int l1 = l, r1 = r, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (a[mid] >= x) r = mid;
    else l = mid + 1;
  }
  if (a[r] != x) return 0;
  int left = r;

  l = l1, r = r1;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (a[mid] <= x) l = mid;
    else r = mid - 1;
  }

  return l - left + 1;
}

int main() {
  #ifdef _DEBUG
  freopen("1102.in", "r", stdin);
  #endif

  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);
  ll res = 0;

  for (int i = 1; i < n; ++i) {
    res += bin_search(0, i - 1, ll(a[i]) - c);
  }
  printf("%lld\n", res);

  return 0;
}
