#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2010;
int a[N][N], b[N], n, m, stk[N], l[N], r[N];

int main() {
  #ifdef _DEBUG
  freopen("3494.in", "r", stdin);
  #endif

  while (~scanf("%d%d", &m, &n)) {
    memset(b, 0, sizeof b);
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &a[i][j]);
        if (a[i][j]) b[j] += a[i][j];
        else b[j] = 0;
      }

      b[0] = b[n + 1] = -1;
      int tt = 0;
      stk[++tt] = 0;
      for (int j = 1; j <= n; ++j) {
        while (b[stk[tt]] >= b[j]) --tt;
        l[j] = stk[tt];
        stk[++tt] = j;
      }

      tt = 0;
      stk[++tt] = n + 1;
      for (int j = n; j >= 1; --j) {
        while (b[stk[tt]] >= b[j]) --tt;
        r[j] = stk[tt];
        stk[++tt] = j;
      }

      for (int j = 1; j <= n; ++j) {
        if (b[j])
          res = max(res, (r[j] - l[j] - 1) * b[j]);
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
