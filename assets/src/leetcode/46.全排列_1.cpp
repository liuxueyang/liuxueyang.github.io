class Solution {
public:
  vector<vector<int>> res;
  vector<int> cur, a;
  vector<bool> vis;
  int n;

  void dfs(int k) {
    if (k == n) {
      res.push_back(cur); return;
    }
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        vis[i] = true;
        cur.push_back(a[i]);
        dfs(k + 1);
        cur.pop_back();
        vis[i] = false;
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    n = nums.size();
    vis = vector<bool> (n, false);
    a = nums;
    dfs(0);

    return res;
  }
};
