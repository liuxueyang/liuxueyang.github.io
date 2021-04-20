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
      if (!st[i]) {
        st[i] = 1;
        cur.push_back(a[i]);

        dfs(k + 1);

        cur.pop_back();
        st[i] = 0;
      }
    }
  }

  vector<vector<int>> permute(vector<int>& _a) {
    n = _a.size();
    a = _a;
    st = VI(n, 0);
    dfs(0);

    return res;
  }
};
