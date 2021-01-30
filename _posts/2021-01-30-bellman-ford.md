---
layout: post
title:  "Bellman-Ford 模板"
date:   2021-01-30 23:00:15 +0800
categories: algorithm bellman-ford
---

[AcWing 853](https://www.acwing.com/problem/content/855/)

最多有 K 條邊，因此最多需要對所有的邊鬆弛 K 次。爲了避免在一次鬆弛的過程中，使用到當前輪計算的結果，導致一次鬆弛得到多次鬆弛的錯誤結果。所以在當前輪鬆弛的時候，應該使用上一輪的結果進行比較。

```cpp
// 853. 有边数限制的最短路

#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f;

struct Edge {
  int a, b, c;
} edge[M];

int n, k, dis[N], bak[N], idx;

void Init() {
  memset(dis, INF, sizeof dis);
  idx = 0;
}

int bellman_ford() {
  dis[1] = 0;

  for (int i = 0; i < k; ++i) {
    memcpy(bak, dis, sizeof dis);

    for (int j = 0; j < idx; ++j) {
      Edge t = edge[j];
      int a = t.a, b = t.b, c = t.c;

      if (bak[a] != INF) {
        int tmp = bak[a] + c;
        if (tmp < dis[b]) {
          dis[b] = tmp;
        }
      }
    }
  }

  return dis[n] == INF ? -1 : dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("853.in", "r", stdin);
  #endif

  int m;
  scanf("%d%d%d", &n, &m, &k);

  Init();

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    Edge t;
    t.a = a; t.b = b; t.c = c;
    edge[idx++] = t;
  }

  int res = bellman_ford();
  if (res == -1)
    printf("impossible\n");
  else
    printf("%d\n", res);

  return 0;
}
```
