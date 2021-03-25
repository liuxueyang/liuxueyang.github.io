class Solution {
public:
  using VI = vector<int>;

  VI a, cur, vis;
  vector<VI> res;
  int n;

  void dfs(int k) {
    if (k == n) {
      res.push_back(cur);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (i && !vis[i - 1] && a[i] == a[i - 1]) continue;

      if (!vis[i]) {
        vis[i] = 1;
        cur.push_back(a[i]);

        dfs(k + 1);

        cur.pop_back();
        vis[i] = 0;
      }
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    a = nums;
    vis = VI(n, 0);

    dfs(0);

    return res;
  }
};
