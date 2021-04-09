#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int n, m, dis[N], st[N], h[N];
int e[N], ne[N], w[N], idx;

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
  st[1] = 1;
  dis[1] = 0;
  queue<int> q({1});

  while (!q.empty()) {
    int t = q.front();
    q.pop();
    st[t] = 0;

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dis[t] + w[i] < dis[j]) {
        dis[j] = dis[t] + w[i];
        if (!st[j]) {
          st[j] = 1;
          q.push(j);
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
