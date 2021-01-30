// 849. Dijkstra求最短路 I

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int g[N][N], dis[N], st[N], n;

void Init() {
  memset(st, 0, sizeof st);
  memset(dis, INF, sizeof dis);
  memset(g, INF, sizeof g);
  for (int i = 1; i <= n; ++i) g[i][i] = 0;
}

int dijkstra() {
  dis[1] = 0;

  for (int i = 0; i < n - 1; ++i) {
    int t = -1;
    for (int j = 1; j <= n; ++j) {
      if (!st[j] && (t == -1 || dis[j] < dis[t]))
        t = j;
    }
    st[t] = 1;
    for (int j = 1; j <= n; ++j) {
      if (g[t][j] != INF) {
        int tmp = dis[t] + g[t][j];
        if (tmp < dis[j]) {
          dis[j] = tmp;
        }
      }
    }
  }

  return dis[n] == INF ? -1 : dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("849.in", "r", stdin);
  #endif

  int m;
  scanf("%d%d", &n, &m);

  Init();

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (g[a][b] > c)
      g[a][b] = c;
  }

  printf("%d\n", dijkstra());

  return 0;
}
