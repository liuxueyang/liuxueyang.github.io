#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;
int g[N][N], st[N], n, dis[N];

int dijkstra() {
  memset(dis, INF, sizeof dis);
  dis[n] = 0;

  for (int i = 0; i < n; ++i) {
    int t = -1;
    for (int j = 1; j <= n; ++j) {
      if (!st[j] && (t == -1 || dis[j] < dis[t]))
	t = j;
    }
    st[t] = 1;
    
    for (int j = 1; j <= n; ++j) {
      if (g[t][j] != INF) {
	dis[j] = min(dis[t] + g[t][j], dis[j]);
      }
    }
  }
  return dis[1] == INF ? -1 : dis[1];
}

void Init() {
  memset(st, 0, sizeof st);
  memset(g, INF, sizeof g);
}

int main() {
  #ifdef _DEBUG
  freopen("2387.in", "r", stdin);
  #endif

  int T;
  while (~scanf("%d%d", &T, &n)) {
    Init();
  
    while (T--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (g[a][b] > c)
	g[a][b] = g[b][a] = c;
    }
    printf("%d\n", dijkstra());
  }


  return 0;
}

