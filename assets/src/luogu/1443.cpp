#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;
using PII = pair<int, int>;

const int N = 410, INF = 0x3f3f3f3f;
int a[N][N], vis[N][N], n, m;

int dir[8][2] = {
  {1, 2}, {1, -2},
  {-1, 2}, {-1, -2},
  {2, 1}, {2, -1},
  {-2, 1}, {-2, -1},
};

bool check(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main() {
  #ifdef _DEBUG
  freopen("1443.in", "r", stdin);
  #endif

  int x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);
  memset(a, INF, sizeof a);
  memset(vis, 0, sizeof vis);
  a[x][y] = 0;
  vis[x][y] = 1;
  queue<PII> q;
  q.push(PII(x, y));
  while (!q.empty()) {
    PII t = q.front(); q.pop();
    x = t.first, y = t.second;
    int x1, y1;
    for (int i = 0; i < 8; ++i) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1) && !vis[x1][y1]) {
        a[x1][y1] = min(a[x1][y1], a[x][y] + 1);
        vis[x1][y1] = 1;
        q.push(PII(x1, y1));
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      printf("%-5d", a[i][j] == INF ? -1 : a[i][j]);
    puts("");
  }

  return 0;
}
