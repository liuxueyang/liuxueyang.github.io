#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 130, INF = 0x3f3f3f3f;
int a[N][N], d[N][N];

int main() {
  #ifdef _DEBUG
  freopen("1719.in", "r", stdin);
  #endif

  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
      d[i][j] += d[i-1][j] + a[i][j];
    }
  }

  int f[N];
  int res = -INF;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      for (int k = 1; k <= n; ++k) {
        f[k] = d[i][k] - d[j-1][k];
      }

      int tmp = f[1];
      res = max(res, tmp);
      for (int k = 2; k <= n; ++k) {
        if (tmp < 0) {
          tmp = f[k];
        } else {
          tmp += f[k];
        }
        res = max(res, tmp);
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
