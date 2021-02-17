#include <cstdio>

const int N = 120;
int b[N], a[N], n;

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

  for (int i = l, j = 0; i <= r; ++i, ++j) q[i] = b[j];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  merge_sort(a, 0, n - 1);

  int k = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[i - 1]) {
      a[k++] = a[i];
    }
  }

  printf("%d\n", k);
  for (int i = 0; i < k; ++i) printf("%d ", a[i]);
  puts("");

  return 0;
}
