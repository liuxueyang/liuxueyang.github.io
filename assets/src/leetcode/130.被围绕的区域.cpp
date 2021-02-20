#include <vector>
#include <cstring>

using namespace std;
const int N = 1010;
int vis[N][N], n, m;

int dir[4][2] = {
  {1, 0}, {-1, 0},
  {0, 1}, {0, -1},
};

bool check(int x, int y) { return x >= 0 && x < n && y > 0 && y < m; }

class Solution {
public:
  vector<vector<char>> a;
  bool mark;

  void dfs(int x, int y) {
    vis[x][y] = 1;
    if (mark) a[x][y] = 'X';

    for (int i = 0; i < 4; ++i) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1)) {
        if (!vis[x1][y1] && a[x1][y1] == 'O') dfs(x1, y1);
      }
    }
  }

  void solve(vector<vector<char>>& board) {
    n = board.size(), m = board[0].size();
    a = board;
    memset(vis, 0, sizeof vis);
    mark = false;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
            a[i][j] == 'O' && !vis[i][j]) dfs(i, j);
      }
    }

    mark = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == 'O' && !vis[i][j]) dfs(i, j);
      }
    }

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
                                  board[i][j] = a[i][j];
  }
};
