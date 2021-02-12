#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100010;
int a[N], L, k, n;

int bsearch(int l, int r) {
  int mid;
  while (l < r) {
    mid = (l + r) >> 1;

    int cnt = 0;
    bool flag = true;
    for (int i = 1; i < n; ++i) {
      int gap = a[i] - a[i - 1];
      if (gap > mid) {
        cnt += gap / mid;
        if (gap % mid == 0) --cnt;
      }
      if (cnt > k) { flag = false; break; }
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
