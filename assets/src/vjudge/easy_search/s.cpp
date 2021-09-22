// TODO:

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;
typedef pair<int, int> PII;

const int dir[4][2] = {
  {1, 0}, {0, 1},
  {-1, 0}, {0, -1},
};
const int N = 110, INF = 0x3f3f3f3f;
bool vis[N][N];
int dis[N][N];
char a[N][N];
int n, m;

int findpath(int s, int e) {
  memset(vis, false, sizeof vis);
  memset(dis, 0x3f, sizeof dis);

  queue<PII> que;
  map<PII, PII> path;

  if (s == 0) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == 'K') {
          vis[i][j] = true;
          dis[i][j] = 0;
          que.push(PII(i, j));
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] - '0' == s) {
          vis[i][j] = 0;
          dis[i][j] = 0;
          que.push(PII(i, j));
        }
      }
    }
  }

  while (!que.empty()) {
    PII t = que.front();
    que.pop();

    int x = t.first, y = t.second, x1, y1;
    vis[x][y] = false;

    for (int i = 0; i < 4; ++i) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (x1 >= 0 && x1 < n &&
          y1 >= 0 && y1 < n &&
          a[x1][y1] != '#') {
        int tmp = dis[x][y] + 1;
        bool snake = false;

        if (a[x1][y1] == 'S') {
          tmp++;
          snake = true;
        }
        if ((tmp < dis[x1][y1]) || (snake && tmp == dis[x1][y1])) {
          dis[x1][y1] = tmp;
          if (!vis[x1][y1]) {
            vis[x1][y1] = true;
            que.push(PII(x1, y1));
            path[PII(x1, y1)] = t;
          }
        }
      }
    }
  }

  int res = INF;
  PII cur;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((e <= m && a[i][j] - '0' == e) || (e > m && a[i][j] == 'T')) {
        if (res > dis[i][j]) {
          res = dis[i][j];
          cur = PII(i, j);
        }
      }
    }
  }

  vector<PII> ps;
  while (path.find(cur) != path.end()) {
    ps.push_back(cur);
    cur = path[cur];
  }

  for (int i = 0; i < int(ps.size()); ++i) {
    int x = ps[i].first, y = ps[i].second;
    if (a[x][y] == 'S') {
      a[x][y] = '.';
    }
  }

  return res;
}

int main(int argc, char *argv[])
{
  #ifdef _DEBUG
  freopen("s.in", "r", stdin);
  #endif

  while (~scanf("%d%d", &n, &m)) {
    if (m + n == 0) break;
    for (int i = 0; i < n; ++i) {
      scanf("%s", a[i]);
    }

    int res = 0;
    for (int i = 0; i <= m; ++i) {
      int tmp = findpath(i, i + 1);
      if (tmp == INF) {
        res = INF;
        break;
      }
      // printf("%d -> %d: %d\n", i, i + 1, tmp);
      res += tmp;
    }

    if (res == INF) printf("impossible\n");
    else printf("%d\n", res);
  }

  return 0;
}

