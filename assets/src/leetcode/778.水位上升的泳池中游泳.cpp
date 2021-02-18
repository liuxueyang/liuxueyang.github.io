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
  bool dfs(int i, int j) {
    if (i == n - 1 && j == n - 1) return true;
    vis[i][j] = true;

    bool flag = false;

    for (int i = 0; i < 4; ++i) {
      int i1 = i + dir[i][0], j1 = j + dir[i][1];
      if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < n) {
        if (!vis[i1][j1] && b[i1][j1] <= m) {
          flag |= dfs(i1, j1);
        }
      }
    }

    if (m == 3 && flag) printf("(%d %d)\n", i, j);
    return flag;
  }
  int swimInWater(vector<vector<int>> &a) {
    n = a.size();
    b = a;

    int l = 0, r = n * n, mid;

    while (l < r) {
      mid = (l + r) >> 1;

      m = mid;
      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) vis[i][j] = false;
      if (dfs(0, 0)) r = mid;
      else l = mid + 1;
    }

    return r;
  }
};
