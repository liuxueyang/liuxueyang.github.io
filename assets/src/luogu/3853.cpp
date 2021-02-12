#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N], n, L, k;

int bsearch(int l, int r) {
  int mid;
  while (l < r) {
    mid = (l + r) >> 1;

    bool flag = true;
    int cnt = 0, prev = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] - prev <= mid) {
        prev = a[i];
        continue;
      }
      else {
        int gap = a[i] - prev;
        if (gap > mid) {
          cnt += gap / mid;
          if (gap % mid == 0) { cnt--; }
        }
        prev = a[i];
        if (cnt > k) { flag = false; break; }
      }
    }

    if (flag) r = mid;
    else l = mid + 1;
  }
  return r;
}

int main(int argc, char *argv[])
{
  #ifdef _DEBUG
  freopen("3853.in", "r", stdin);
  #endif

  scanf("%d%d%d", &L, &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  sort(a, a + n);
  printf("%d\n", bsearch(1, L));

  return 0;
}
