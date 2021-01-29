#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 510, INF=0x3f3f3f3f;
int n, g[N][N], dis[N], st[N], cnt[N];

void Init() {
  memset(st, 0, sizeof st);
  memset(dis, INF, sizeof dis);
  memset(cnt, 0, sizeof cnt);
}

bool spfa() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    q.push(i);
    st[i] = 1;
  }

  while (!q.empty()) {
    int t = q.front(); q.pop();
    st[t] = 0;
    for (int i = 1; i <= n; ++i) {
      if (t == i) continue;
      if (g[t][i] != INF) {
	int tmp = dis[t] + g[t][i];
	if (tmp < dis[i]) {
	  dis[i] = tmp;
	  cnt[i] = cnt[t] + 1;
	  if (cnt[i] >= n) return true;
	  if (!st[i]) {
	    st[i] = 1;
	    q.push(i);
	  }
	}
      }
    }
  }
  return false;
}

int main() {
  #ifdef _DEBUG
  freopen("3259.in", "r", stdin);
  #endif
  
  int F;
  scanf("%d", &F);
  while (F--) {
    Init();
    int m, w;
    scanf("%d%d%d", &n, &m, &w);

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
	if (i == j) g[i][j] = 0;
	else g[i][j] = INF;
    
    for (int i = 1; i <= m; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (a == b) continue;
      if (g[a][b] > c) {
	g[a][b] = g[b][a] = c;
      }
    }
    for (int i = 1; i <= w; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      g[a][b] = -c;
    }

    printf("%s\n", (spfa() ? "YES" : "NO"));
  }
  
  return 0;
}

/*
  AC
  spfa 判断负环
  注意这个题目有重边，留下一个比较短的边就可以
 */
