#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
using PII = pair<int, int>;

const int INF = 0x3f3f3f3f, N = 210;
int a[N], vis[N], n, x, y, b[N];
int dir[2] = {1, -1};

int main() {
  #ifdef _DEBUG
  freopen("1135.in", "r", stdin);
  #endif

  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i);
  memset(vis, 0, sizeof vis);
  memset(a, 0x3f, sizeof a);
  a[x] = 0; vis[x] = 1;
  queue<int> q; q.push(x);
  while (!q.empty()) {
    int x1 = q.front(); q.pop();
    if (x1 == y) {
      printf("%d\n", a[x1]); return 0;
    }

    for (int i = 0; i < 2; ++i) {
      int x2 = x1 + b[x1] * dir[i];
      if (x2 >= 1 && x2 <= n && !vis[x2]) {
        vis[x2] = 1; q.push(x2);
        a[x2] = min(a[x2], a[x1] + 1);
      }
    }
  }
  printf("-1\n");

  return 0;
}
