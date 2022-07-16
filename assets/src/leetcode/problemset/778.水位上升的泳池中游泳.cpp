#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
  vector<vector<int>> b;
  int n, m;
  int dir[4][2] = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0},
  };
  bool vis[55][55];

  bool dfs(int x, int y) {
    if (x == n - 1 && y == n - 1) return true;
    vis[x][y] = true;

    bool flag = false;

    for (int i = 0; i < 4; ++i) {
      int i1 = x + dir[i][0], j1 = y + dir[i][1];

      if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
        if (!vis[i1][j1] && b[i1][j1] <= m) {
          flag |= dfs(i1, j1);
        }
      }
    }

    return flag;
  }
  int swimInWater(vector<vector<int>> &a) {
    n = a.size();
    b = a;

    int l = a[0][0], r = n * n, mid;

    while (l < r) {
      mid = (l + r) >> 1;

      m = mid;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) vis[i][j] = false;
      if (dfs(0, 0)) r = mid;
      else l = mid + 1;
    }

    return r;
  }
};

int main() {
  vector<vector<int>> v{
    {0, 2},
    {1, 3},
  };
  Solution a;
  int ans = a.swimInWater(v);
  printf("%d\n", ans);

  return 0;
}
