class Solution {
public:
  vector<vector<int>> res;
  vector<int> a, cur;
  vector<bool> vis;
  int n;

  void dfs(int k) {
    if (k == n) { res.push_back(cur); return; }
    for (int i = 0; i < n; ++i) {
      if (i && a[i] == a[i - 1] && !vis[i - 1]) continue;
      if (!vis[i]) {
        vis[i] = true;
        cur.push_back(a[i]);

        dfs(k + 1);

        cur.pop_back();
        vis[i] = false;
      }
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    a = nums;
    vis = vector<bool> (n, false);
    dfs(0);

    return res;
  }
};
