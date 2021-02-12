#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5000010;
int n, a[N];

int Qsort(int l, int r, int k) {
  if (l == r) return a[l];
  int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
  while (i < j) {
    while (a[++i] < x) ;
    while (a[--j] > x) ;
    if (i < j) swap(a[i], a[j]);
  }
  int le = j - l + 1;
  if (k <= le) return Qsort(l, j, k);
  else return Qsort(j + 1, r, k - le);
}

int main(int argc, char *argv[])
{
  #ifdef _DEBUG
  freopen("1923.in", "r", stdin);
  #endif
  int k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  printf("%d\n", Qsort(0, n - 1, k + 1));

  return 0;
}
