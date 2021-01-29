#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, g[N][N], dis[N], st[N], cnt[N];

void Init() {
  memset(dis, INF, sizeof dis);
  memset(st, 0, sizeof st);
  memset(cnt, 0, sizeof cnt);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i == j) g[i][j] = 0;
      else g[i][j] = INF;
}

bool spfa() {
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    q.push(i);
    st[i] = 1;
  }

  while (!q.empty()) {
    int t = q.front();
    q.pop();
    st[t] = 0;

    for (int i = 1; i <= n; ++i) {
      if (t == i) continue;
      if (g[t][i] != INF) {
        int tmp = dis[t] + g[t][i];
        if (tmp < dis[i]) {
          dis[i] = tmp;
          cnt[i] = cnt[t] + 1;

          if (cnt[i] >= n) return true;
          if (!st[i]) {
            st[i] = 1;
            q.push(i);
          }
        }
      }
    }
  }
  return false;
}

int main() {
#ifdef _DEBUG
  freopen("3259.in", "r", stdin);
#endif

  int F;
  scanf("%d", &F);
  while (F--) {
    int m, w;
    scanf("%d%d%d", &n, &m, &w);

    Init();

    for (int i = 1; i <= m; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (a == b) continue;
      if (g[a][b] > c) g[a][b] = g[b][a] = c;
    }

    for (int i = 1; i <= w; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      g[a][b] = -c;
    }

    printf("%s\n", (spfa() ? "YES" : "NO"));
  }

  return 0;
}

/*
 * 厲害了哈哈，調了半天，原來是把代碼寫到了 ifdef 塊裏面
 */
