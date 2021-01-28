#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;
int g[N][N], dis[N], st[N], n, sa, dis1[N];

void Init() {
  memset(st, 0, sizeof st);
  memset(dis, INF, sizeof dis);
}

void dijkstra() {
  dis[sa] = 0;

  for (int i = 0; i < n; ++i) {
    int t = -1;
    for (int j = 1; j <= n; ++j) {
      if (!st[j] && (t == -1 || dis[j] < dis[t]))
	t = j;
    }
    st[t] = 1;
    for (int j = 1; j <= n; ++j) {
      if (g[t][j] != INF) {
	dis[j] = min(dis[j], dis[t] + g[t][j]);
      }
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("3268.in", "r", stdin);
  #endif

  int m;
  while (~scanf("%d%d%d", &n, &m, &sa)) {
    memset(g, INF, sizeof g);
    Init();
    
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      g[a][b] = c;
    }

    dijkstra();
    
    for (int i = 1; i <= n; ++i) dis1[i] = dis[i];

    Init();
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
	swap(g[i][j], g[j][i]);
      }
    }
    
    dijkstra();

    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (dis[i] == INF || dis1[i] == INF || i == sa)
	continue;
      res = max(res, dis[i] + dis1[i]);
    }

    printf("%d\n", res);
  }
  
  return 0;
}

/*
  两次 Dij 就可以
  实现的时候出现的 Bug 是第二次初始化的时候，把 g 给清空了
  导致第二次 Dij 的结果不对，修改测试样例，
  然后打印中间结果才发现
 */
