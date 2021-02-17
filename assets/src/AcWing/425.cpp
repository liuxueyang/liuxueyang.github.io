#include <cstdio>

using namespace std;

const int N = 110;
int a[N], b[N], n;

void merge_sort(int q[], int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  merge_sort(q, l, mid);
  merge_sort(q, mid + 1, r);

  int i = l, j = mid + 1, k = 0;
  while (i <= mid && j <= r) {
    if (q[i] <= q[j]) b[k++] = q[i++];
    else b[k++] = q[j++];
  }
  while (i <= mid) b[k++] = q[i++];
  while (j <= r) b[k++] = q[j++];

  for (i = l, j = 0; i <= r; ++i, ++j) q[i] = b[j];
  return;
}

int main() {
  #ifdef _DEBUG
  freopen("425.in", "r", stdin);
  #endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  merge_sort(a, 1, n);

  int k = 1;
  for (int i = 2; i <= n; ++i)
    if (a[i] != a[i - 1])
      a[++k] = a[i];

  printf("%d\n", k);

  for (int i = 1; i <= k; ++i) {
    printf("%d ", a[i]);
  }
  puts("");

  return 0;
}
