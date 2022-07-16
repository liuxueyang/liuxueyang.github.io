#include <vector>
#include <cstring>

using namespace std;

const int N = 310;
int vis[N][N], n, m;

int dir[4][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
};
bool check(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }

class Solution {
public:
  int ans;
  vector<vector<char>> a;
  void dfs(int x, int y) {
    vis[x][y] = 1;

    int x1, y1;
    for (int i = 0; i < 4; ++i) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1)) {
        if (!vis[x1][y1] && a[x1][y1] == '1') dfs(x1, y1);
      }
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    memset(vis, 0, sizeof vis);
    ans = 0;
    n = grid.size(), m = grid[0].size();
    a = grid;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (!vis[i][j] && a[i][j] == '1') { ++ans; dfs(i, j); }
      }
    }

    return ans;
  }
};
