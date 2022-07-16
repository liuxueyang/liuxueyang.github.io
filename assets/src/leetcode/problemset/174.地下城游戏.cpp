#include <algorithm>
#include <vector>
#include <vector>

using namespace std;

const int N = 100;
int vis[N][N], tot, b[N][N], m, n;
int dir[4][2] = {
  {1, 0}, {-1, 0},
  {0, 1}, {0, -1},
};

int T;

class Solution {
public:
  int n, m;

  bool dfs(int r, int x, int y) {
    if (x == n - 1 && y == m - 1) {
      return r > 0;
    }

    if (r <= 0) return false;

    vis[x][y] = 1;

    bool flag = false;

    for (int i = 0; i < 4; ++i) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];

      if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
        if (!vis[x1][y1] && r + b[x1][y1] > 0) {
          flag |= dfs(r + b[x1][y1], x1, y1);

          if (flag) {
            if (T == 4) {
              printf("r=%d, (%d %d)\n", r, x, y);
            }
          }

          if (flag) return true;
        }
      }
    }

    vis[x][y] = 0;

    return flag;
  }

  int calculateMinimumHP(vector<vector<int>>& a) {
    n = a.size(), m = a[0].size();

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        b[i][j] = a[i][j];

    int l = 1, r = 1e9, mid;
    while (l < r) {
      mid = (l + r) >> 1;

      T = mid + a[0][0];

      memset(vis, 0, sizeof vis);
      if (dfs(mid + a[0][0], 0, 0)) r = mid;
      else l = mid + 1;
    }

    return r;
  }
};

int main() {
  Solution a;
  vector<vector<int>> v {
    {0,-74,-47,-20,-23,-39,-48},
    {37,-30,37,-65,-82,28,-27},
    {-76,-33,7,42,3,49,-93},
    {37,-41,35,-16,-96,-56,38},
    {-52,19,-37,14,-65,-42,9},
    {5,-26,-30,-65,11,5,16},
    {-60,9,36,-36,41,-47,-86},
    {-22,19,-5,-41,-8,-96,-95},
  };
  int ans = a.calculateMinimumHP(v);
  printf("%d\n", ans);

  return 0;
}
