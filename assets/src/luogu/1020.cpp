#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 100010;
int a[N], d[N], n, f[N];

int main() {
  #ifdef _DEBUG
  freopen("1020.in", "r", stdin);
  #endif

  n = 0;
  int t;
  while (~scanf("%d", &t)) {
    a[++n] = t;
  }
  for (int i = 1; i <= n; ++i) d[i] = 1;
  int res = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (a[i] <= a[j]) {
        if (d[j] + 1 > d[i]) d[i] = d[j] + 1;
        if (res < d[i]) res = d[i];
      }
    }
  }
  printf("%d\n", res);

  int sz = 1;
  f[sz] = a[1];
  for (int i = 2; i <= n; ++i) {

    int pos = -1;
    for (int j = 1; j <= sz; ++j) {
      if (f[j] < a[i]) continue;
      if (pos == -1 || f[pos] > f[j]) pos = j;
    }

    if (pos == -1) f[++sz] = a[i];
    else f[pos] = a[i];
  }
  printf("%d\n", sz);

  return 0;
}
