class Solution {
public:
  using VI = vector<int>;

  vector<VI> res;
  VI a, cur;
  int n;

  void dfs(int k) {
    if (k == n) { res.push_back(cur); return; }

    int c = 0;
    while (k + c < n && a[k] == a[k + c]) ++c;

    dfs(k + c);

    for (int i = 0; i < c; ++i) {
      cur.push_back(a[k]);
      dfs(k + c);
    }
    for (int i = 0; i < c; ++i) cur.pop_back();
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    n = nums.size();
    sort(nums.begin(), nums.end());
    a = nums;

    dfs(0);

    return res;
  }
};
