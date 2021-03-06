// 851. spfa求最短路

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int n, dis[N], st[N], w[N];
int h[N], e[N], ne[N], idx;

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void Init() {
  memset(h, -1, sizeof h);
  memset(dis, INF, sizeof dis);
  memset(st, 0, sizeof st);
  idx = 0;
}

int spfa() {
  dis[1] = 0;
  queue<int> que;
  que.push(1);

  while (!que.empty()) {
    int t = que.front();
    que.pop();
    st[t] = 0;

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      int tmp = dis[t] + w[i];
      if (tmp < dis[j]) {
        dis[j] = tmp;
        if (!st[j]) {
          st[j] = 1;
          que.push(j);
        }
      }
    }
  }

  return dis[n] == INF ? -1 : dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("851.in", "r", stdin);
  #endif

  int m;
  scanf("%d%d", &n, &m);

  Init();

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    Add(a, b, c);
  }

  int res = spfa();
  if (res == -1) printf("impossible\n");
  else printf("%d\n", res);

  return 0;
}
