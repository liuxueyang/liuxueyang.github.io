#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using PII = pair<int, int>;

const int N = 10010, M = 500010, INF = 0x3f3f3f3f;

int n, m, s, h[N], dis[N], st[N];
int idx, e[M], ne[M], w[M];

void Init() {
  idx = 0;
  memset(dis, 0x3f, sizeof dis);
  memset(h, -1, sizeof h);
  memset(st, 0, sizeof st);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
  st[s] = 1, dis[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, s});

  while (!q.empty()) {
    auto x = q.top(); q.pop();
    int t = x.second;
    st[t] = 0;

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dis[t] + w[i] < dis[j]) {
        dis[j] = dis[t] + w[i];
        if (!st[j]) {
          st[j] = 1;
          q.push({dis[j], j});
        }
      }
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("3371.in", "r", stdin);
  #endif

  Init();
  scanf("%d%d%d", &n, &m, &s);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    Add(a, b, c);
  }

  dijkstra();

  for (int i = 1; i <= n; ++i) {
    printf("%lld ", dis[i] == INF ? (1LL<<31) - 1 : dis[i]);
  }
  puts("");

  return 0;
}
