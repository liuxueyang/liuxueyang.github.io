#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int N = 100010;
int a[N], n;

void Qsort(int l, int r) {
  if (l >= r) return;
  int i = l - 1, j = r + 1, x = a[l + r >> 1];
  while (i < j) {
    while (a[++i] < x);
    while (a[--j] > x);
    if (i < j) swap(a[i], a[j]);
  }
  Qsort(l, j);
  Qsort(j + 1, r);
}

int main() {
  #ifdef _DEBUG
  freopen("1177.in", "r", stdin);
  #endif

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  Qsort(0, n - 1);
  for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == (n-1) ? '\n' : ' ');
  return 0;
}
