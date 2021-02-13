#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;

int a[N][N], n, m, d[N][N], vis[N][N];
const int dir[4][2] = {
  {0, 1}, {0, -1},
  {-1, 0}, {1, 0},
};

int dfs(int i, int j) {
  if (vis[i][j]) return d[i][j];
  vis[i][j] = 1;
  int cur = 0;
  for (int k = 0; k < 4; ++k) {
    int i1 = i + dir[k][0],
      j1 = j + dir[k][1];
    if (i1 >= 1 && i1 <= n &&
	j1 >= 1 && j1 <= m) {
      if (a[i][j] > a[i1][j1]) {
	cur = max(cur, dfs(i1, j1));
      }
    }
  }
  return d[i][j] = cur + 1;
}

int main() {
  #ifdef _DEBUG
  freopen("1434.in", "r", stdin);
  #endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      d[i][j] = 1;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      res = max(res, dfs(i, j));
    }
  }

  printf("%d\n", res);
  
  return 0;
}
