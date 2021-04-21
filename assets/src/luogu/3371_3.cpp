#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

using PII = pair<int, int>;

const int INF = 0x3f3f3f3f, N = 10010, M = 500010;

int n, m, s, dis[N], st[N], h[N];
int e[M], ne[M], w[M], idx;

void Init() {
  idx = 0;
  memset(dis, 0x3f, sizeof dis);
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
  st[s] = 1, dis[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, s});

  while (!q.empty()) {
    auto x = q.top();
    q.pop();
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
    printf("%lld ", dis[i] == INF ? (1LL << 31) - 1 : dis[i]);
  }
  puts("");

  return 0;
}
