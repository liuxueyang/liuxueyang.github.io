#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;
const int N = 1010, INF = 0x3f3f3f3f;
int a[N][N], c, n, m;
ll d[N][N];

int main() {
  #ifdef _DEBUG
  freopen("2004.in", "r", stdin);
  #endif

  scanf("%d%d%d", &n, &m, &c);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      d[i][j] = d[i-1][j] + d[i][j-1] + a[i][j] - d[i-1][j-1];
    }
  }
  ll res = -INF;
  int rx, ry;
  for (int i = 1; i + c - 1<= n; ++i) {
    for (int j = 1; j + c - 1 <= m; ++j) {
      int i1 = i + c - 1, j1 = j + c - 1;
      ll tmp = d[i1][j1] + d[i-1][j-1] - d[i-1][j1] - d[i1][j-1];
      if (tmp > res) {
        res = tmp;
        rx = i;
        ry = j;
      }
    }
  }
  printf("%d %d\n", rx, ry);

  return 0;
}
