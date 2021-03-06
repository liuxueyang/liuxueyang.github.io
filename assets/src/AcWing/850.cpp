#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 200010, INF = 0x3f3f3f3f;
int w[N], dis[N], st[N], n;
int e[N], ne[N], h[N], idx;

void Init() {
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
  idx = 0;
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
  memset(dis, INF, sizeof dis);
  dis[1] = 0;

  priority_queue<PII, vector<PII>, greater<PII> > que;
  que.push(PII(0, 1));

  while (!que.empty()) {
    PII t = que.top();
    que.pop();

    int ver = t.second, base = t.first;
    if (st[ver]) continue;
    st[ver] = 1;

    for (int j = h[ver]; j != -1; j = ne[j]) {
      int u = e[j];
      if (base + w[j] < dis[u]) {
	dis[u] = base + w[j];
	// printf("u=%d dis[u]=%d\n", u, dis[u]);
	que.push(PII(dis[u], u));
      }
    }
  }
  return dis[n] == INF ? -1 : dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("850.in", "r", stdin);
  #endif
  
  int T;
  while (~scanf("%d%d", &n, &T)) {
    Init();
  
    while (T--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      Add(a, b, c);
    }
    printf("%d\n", dijkstra());
  }

  return 0;
}
