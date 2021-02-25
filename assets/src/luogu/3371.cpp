#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using PII = pair<int, int>;
using ll = long long;

const int N = 10010, M = 500010, INF = 0x3f3f3f3f;
int n, m, s, idx; int e[M], ne[M], w[M];
int h[N], dis[N], st[N];
void Init() {
  idx = 0; memset(h, -1, sizeof h);
  memset(dis, 0x3f, sizeof dis);
  memset(st, 0, sizeof st);
}
void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void dijkstra() {
  priority_queue<PII, vector<PII>, greater<PII>> p;
  dis[s] = 0;
  p.push(PII(0, s));
  while (!p.empty()) {
    PII t = p.top(); p.pop();
    int ver = t.second, base = t.first;
    if (st[ver]) continue;
    st[ver] = 1;
    for (int j = h[ver]; j != -1; j = ne[j]) {
      int u = e[j];
      if (base + w[j] < dis[u]) {
        dis[u] = base + w[j];
        p.push(PII(dis[u], u));
      }
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("3371.in", "r", stdin);
  #endif

  scanf("%d%d%d", &n, &m, &s);
  Init();
  while (m--) {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    Add(a, b, c);
  }
  dijkstra();
  for (int i = 1; i <= n; ++i)
    printf("%lld ", dis[i]==INF ? ((1LL<<31) - 1) : ll(dis[i]));
  puts("");

  return 0;
}
