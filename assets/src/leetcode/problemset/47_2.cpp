using VI = vector<int>;

class Solution {
public:
  VI a, cur, st;
  vector<VI> res;
  int n;

  void dfs(int k) {
    if (k == n) {
      res.push_back(cur);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (i && a[i] == a[i - 1] && !st[i - 1]) continue;
      if (!st[i]) {
        st[i] = 1;

        cur[k] = a[i];
        dfs(k + 1);

        st[i] = 0;
      }
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& _a) {
    sort(_a.begin(), _a.end());
    n = _a.size();
    a = _a;
    cur = VI(n, 0);
    st = VI(n, 0);

    dfs(0);

    return res;
  }
};
