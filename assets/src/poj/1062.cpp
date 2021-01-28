#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int dis[N], w[N], L[N], n, M,
  g[N][N], st[N], res, lmi[N], lma[N];

void Init() {
  memset(dis, INF, sizeof dis);
  memset(st, 0, sizeof st);
  memset(g, INF, sizeof g);
  res = INF;
}

void dijkstra() {
  dis[1] = 0;
  lmi[1] = lma[1] = L[1];
  res = min(res, dis[1] + w[1]);

  for (int i = 0; i < n; ++i) {
    int t = -1;
    for (int j = 1; j <= n; ++j) {
      if (!st[j] && (t == -1 || dis[j] < dis[t])) {
	t = j;
      }
    }
    st[t] = 1;

    for (int j = 1; j <= n; ++j) {
      int mi = min(lmi[t], L[j]),
	ma = max(lma[t], L[j]), ga = abs(mi - ma);
      if (g[t][j] != INF && ga <= M) {
	dis[j] = min(dis[j], dis[t] + g[t][j]);
	lmi[j] = mi;
	lma[j] = ma;
	res = min(res, dis[j] + w[j]);
      }
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("1062.in", "r", stdin);
  #endif

  Init();
  scanf("%d%d", &M, &n);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d%d%d", &w[i], &L[i], &x);
    while (x--) {
      int k, c;
      scanf("%d%d", &k, &c);
      g[i][k] = c;
    }
  }
  dijkstra();
  printf("%d\n", res);
  
  return 0;
}

/*
  竟然 1A 了，有趣
  首先把图反向
  由于最终的费用是路径上的费用和加上终点的费用，因此需要维护
  路径的费用和即可。求结果的时候临时加上终点的费用。
  维护当前看到的最大 Level 和最小 Level 作为松弛时候的判断条件
 */
