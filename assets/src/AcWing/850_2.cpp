#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 200010, INF = 0x3f3f3f3f;

int n, dis[N], st[N];
int h[N], e[N], ne[N], w[N], idx;

void Init() {
  memset(h, -1, sizeof h);
  memset(dis, INF, sizeof dis);
  memset(st, 0, sizeof st);
  idx = 0;
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
  dis[1] = 0;
  priority_queue<PII, vector<PII>, greater<PII> > que;
  que.push(PII(0, 1));

  while (!que.empty()) {
    PII t = que.top();
    que.pop();
    int ver = t.second, base = t.first;
    if (st[ver]) continue;
    st[ver] = 1;

    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i];
      int tmp = base + w[i];
      if (tmp < dis[j]) {
        dis[j] = tmp;
        que.push(PII(dis[j], j));
      }
    }
  }

  return dis[n] == INF ? -1 : dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("850.in", "r", stdin);
  #endif

  int m;
  scanf("%d%d", &n, &m);

  Init();

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    Add(a, b, c);
  }

  printf("%d\n", dijkstra());

  return 0;
}
