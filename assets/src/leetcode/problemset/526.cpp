const int N = 17;
int vis[N];

class Solution {
public:
  int res, n;

  void dfs(int k) {
    if (k == n + 1) {
      ++res;
      return;
    }

    for (int i = 1; i <= n; ++i) {
      if (!vis[i] && (i % k == 0 || k % i == 0)) {
        vis[i] = 1;
        dfs(k + 1);
        vis[i] = 0;
      }
    }
  }

  int countArrangement(int _n) {
    res = 0;
    n = _n;
    memset(vis, 0, sizeof vis);

    dfs(1);

    return res;
  }
};
