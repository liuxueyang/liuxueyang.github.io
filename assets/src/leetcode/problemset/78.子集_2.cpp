class Solution {
public:
  using VI = vector<int>;
  vector<VI> res;
  VI cur, a;
  int n;

  void dfs(int k) {
    if (k == n) { res.push_back(cur); return; }
    dfs(k + 1);
    cur.push_back(a[k]);
    dfs(k + 1);
    cur.pop_back();
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    n = nums.size(); a = nums;
    dfs(0);
    return res;
  }
};
