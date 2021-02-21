class Solution {
public:
  vector<int> cur, a;
  vector<vector<int>> res;
  int n;

  void dfs(int k) {
    if (k == n) {
      res.push_back(cur); return;
    }

    int c = 0;
    while (k + c < n && a[k] == a[k + c]) ++c;

    for (int i = 0; i <= c; ++i) {
      dfs(k + c);
      cur.push_back(a[k]);
    }

    for (int i = 0; i <= c; ++i)
      cur.pop_back();
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    a = nums;

    dfs(0);

    return res;
  }
};
