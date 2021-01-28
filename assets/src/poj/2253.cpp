#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

int n, x[N], y[N], m, dis[N], st[N], sa, en, g[N][N];

int dijkstra() {
  memset(dis, INF, sizeof dis);
  dis[sa] = 0;

  for (int i = 0; i < n; ++i) {
    int t = -1;
    for (int j = 1; j <= n; ++j) {
      if (!st[j] && (t == -1 || dis[j] < dis[t])) t = j;
    }
    st[t] = 1;
    for (int j = 1; j <= n; ++j) {
      dis[j] = min(dis[j], max(g[t][j], dis[t]));
    }
  }
  return dis[en];
}

void Init() {
  memset(st, 0, sizeof st);
  memset(g, 0, sizeof g);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) {
	g[i][j] = 0; continue;
      }
      int dx = x[i] - x[j], dy = y[i] - y[j];
      g[i][j] = dx * dx + dy * dy;
    }
  }
}

int main() {
#ifdef _DEBUG
  freopen("2253.in", "r", stdin);
#endif

  int T = 1;
  while (~scanf("%d", &n) && n) {
    sa = 1, en = 2;
    scanf("%d%d%d%d", x+1, y+1, x+2, y+2);
    for (int j = 3; j <= n; ++j) scanf("%d%d", x+j, y+j);

    Init();
    double res = dijkstra();
    printf("Scenario #%d\nFrog Distance = %.3f\n\n",
	   T, sqrt(res));
    T++;
  }
  return 0;
}
