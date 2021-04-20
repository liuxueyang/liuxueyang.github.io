#include <queue>
#include <cstdio>
#include <cstring>
#include <vector>
#include <tuple>

using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;

const int N = 100010, M = N, INF = 0x3f3f3f3f;

int n, m, h[N], dis[N], st[N];
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

int spfa() {
  st[1] = 1, dis[1] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, 1});

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

  return dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("851.in", "r", stdin);
  #endif

  Init();
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    Add(a, b, c);
  }

  int res = spfa();
  res == INF ? printf("impossible\n") : printf("%d\n", res);

  return 0;
}
