const int N = 20;
int d[2*N+10], d1[2*N+10], vis[N], col[N];

class Solution {
public:
  vector<vector<string>> res;
  int n;

  void dfs(int k) {
    if (k == n + 1) {
      vector<string> cur;
      for (int i = 1; i <= n; ++i) {
        string tmp(n, '.');
        tmp[col[i] - 1] = 'Q';
        cur.push_back(tmp);
      }
      res.push_back(cur);
      return;
    }
    for (int i = 1; i <= n; ++i) {
      if (!vis[i] && !d[i + k] && !d1[i - k + n]) {
        vis[i] = d[i + k] = d1[i - k + n] = 1;
        col[k] = i;
        dfs(k + 1);
        vis[i] = d[i + k] = d1[i - k + n] = 0;
      }
    }
  }

  vector<vector<string>> solveNQueens(int _n) {
    n = _n;
    memset(d, 0, sizeof d);
    memset(d1, 0, sizeof d1);
    memset(vis, 0, sizeof vis);
    memset(col, 0, sizeof col);

    dfs(1);

    return res;
  }
};
