#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
using PII = pair<int, int>;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;
int dis[N], st[N], n, m, s, h[N];
int e[M], ne[M], w[M], idx;

void Init() {
  idx = 0;
  memset(dis, INF, sizeof dis);
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
  dis[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, s});
  while (!q.empty()) {
    PII t = q.top(); q.pop();
    int ver = t.second, base = t.first;
    if (st[ver]) continue;
    st[ver] = 1;
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dis[j] > base + w[i]) {
        dis[j] = base + w[i];
        q.push({dis[j], j});
      }
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("4779.in", "r", stdin);
  #endif

  Init();
  scanf("%d%d%d", &n, &m, &s);
  while (m--) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    Add(a, b, c);
  }
  dijkstra();
  for (int i = 1; i <= n; ++i) {
    printf("%lld ", dis[i] == INF ? ((1LL<<31) - 1) : dis[i]);
  }
  puts("");

  return 0;
}
