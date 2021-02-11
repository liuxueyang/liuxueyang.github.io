#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;
const int N = 100010;
int a[N], b[N], n, m;

int main() {
  #ifdef _DEBUG
  freopen("1678.in", "r", stdin);
  #endif

  ll res = 0;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; ++i) scanf("%d", a+i);
  for (int i = 0; i < n; ++i) scanf("%d", b+i);
  sort(a, a + m);

  for (int i = 0; i < n; ++i) {
    int l = 0, r = m - 1, mid;
    int x = b[i];
    while (l < r) {
      mid = (l + r) >> 1;
      if (a[mid] >= x) r = mid;
      else l = mid + 1;
    }

    int del = 0;
    if (a[r] != x) {
      if (r == 0) del = abs(a[r] - x);
      else del = min(abs(a[r] - x), abs(x - a[r-1]));
    }

    res += del;
  }
  printf("%lld\n", res);

  return 0;
}
