#include <cstdio>

using namespace std;
using ll = long long;

const int N = 100010;
int a[N], n;

int bsearch(int l, int r) {
  int mid;
  while (l < r) {
    mid = (l + r) >> 1;

    bool flag = true;
    ll x = mid;
    for (int i = 1; i <= n; ++i) {
      x = 2 * x - a[i];
      if (x >= N) x = N;
      if (x < 0) { flag = false; break; }
    }

    if (flag) r = mid;
    else l = mid + 1;
  }
  return r;
}

int main() {
  #ifdef _DEBUG
  freopen("730.in", "r", stdin);
  #endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  printf("%d\n", bsearch(1, N));

  return 0;
}
