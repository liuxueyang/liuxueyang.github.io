const int N = 30;
int vis[N], n;

class Solution {
public:
  vector<int> a, cur;
  vector<vector<int>> res;

  void dfs(int k) {
    if (k == n) {
      res.push_back(cur);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (i && a[i] == a[i - 1] && !vis[i-1]) continue;
      if (!vis[i]) {
        vis[i] = 1;

        cur[k] = a[i];
        dfs(k + 1);

        vis[i] = 0;
      }
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    a = nums;
    memset(vis, 0, sizeof vis);
    cur = vector<int> (n, 0);
    dfs(0);

    return res;
  }
};
