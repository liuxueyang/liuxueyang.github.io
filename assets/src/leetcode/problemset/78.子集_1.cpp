class Solution {
public:
  vector<vector<int>> res;
  vector<int> a, cur;
  int n;

  void dfs(int k) {
    if (k == n) { res.push_back(cur); return; }

    for (int i = 0; i <= 1; ++i) {
      dfs(k + 1);
      cur.push_back(a[k]);
    }

    for (int i = 0; i <= 1; ++i) cur.pop_back();
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    n = nums.size();
    a = nums;
    dfs(0);

    return res;
  }
};
