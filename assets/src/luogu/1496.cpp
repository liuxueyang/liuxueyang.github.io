#include <cstdio>
#include <algorithm>
#include <tuple>

using namespace std;
using PII = pair<int, int>;
using ll = long long;

const int N = 20010;
PII a[N];
int n;

int main() {
  #ifdef _DEBUG
  freopen("1496.in", "r", stdin);
  #endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[i] = PII(x, y);
  }
  sort(a + 1, a + n + 1);

  ll res = 0;
  int x1 = a[1].first, y1 = a[1].second;

  for (int i = 2; i <= n; ++i) {
    if (y1 >= a[i].first) {
      y1 = max(y1, a[i].second);
    } else {
      res += (y1 - x1);
      x1 = a[i].first;
      y1 = a[i].second;
    }
  }
  res += (y1 - x1);

  printf("%lld\n", res);

  return 0;
}
