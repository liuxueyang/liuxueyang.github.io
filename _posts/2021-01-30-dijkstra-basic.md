---
layout: post
title:  "Dijkstra 模板"
date:   2021-01-30 21:55:42 +0800
categories: algorithm dijkstra
---

# 樸素 Dijkstra

[AcWing 849](https://www.acwing.com/problem/content/851/)

```cpp
// 849. Dijkstra求最短路 I

#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int g[N][N], dis[N], st[N], n;

void Init() {
  memset(st, 0, sizeof st);
  memset(dis, INF, sizeof dis);
  memset(g, INF, sizeof g);
  for (int i = 1; i <= n; ++i) g[i][i] = 0;
}

int dijkstra() {
  dis[1] = 0;

  for (int i = 0; i < n - 1; ++i) {
    int t = -1;
    for (int j = 1; j <= n; ++j) {
      if (!st[j] && (t == -1 || dis[j] < dis[t]))
        t = j;
    }
    st[t] = 1;
    for (int j = 1; j <= n; ++j) {
      if (g[t][j] != INF) {
        int tmp = dis[t] + g[t][j];
        if (tmp < dis[j]) {
          dis[j] = tmp;
        }
      }
    }
  }

  return dis[n] == INF ? -1 : dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("849.in", "r", stdin);
  #endif

  int m;
  scanf("%d%d", &n, &m);

  Init();

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (g[a][b] > c)
      g[a][b] = c;
  }

  printf("%d\n", dijkstra());

  return 0;
}
```

# 堆優化 Dijkstra

![AcWing 850](https://www.acwing.com/problem/content/852/)

``` cpp
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

```
