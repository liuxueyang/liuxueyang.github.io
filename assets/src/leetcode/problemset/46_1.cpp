class Solution {
public:
  using VI = vector<int>;

  vector<VI> res;
  int n;
  VI a, cur, vis;

  void dfs(int k) {
    if (k == n) {
      res.push_back(cur);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        vis[i] = 1;
        cur.push_back(a[i]);
        dfs(k + 1);
        cur.pop_back();
        vis[i] = 0;
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    n = nums.size();
    a = nums;
    vis = VI(n, 0);
    dfs(0);

    return res;
  }
};
