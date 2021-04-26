const int N = 1010;
char s[N], p[N];
int ne[N], n, m;

using VI = vector<int>;

class Solution {
public:
  vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
    vector<VI> res;

    for (int i = 0; i < big.size(); ++i) s[i + 1] = big[i];

    n = big.size();

    for (auto &x : smalls) {
      for (int i = 0; i < x.size(); ++i) p[i + 1] = x[i];
      VI cur;

      memset(ne, 0, sizeof ne);
      m = x.size();

      if (!m) {
        res.push_back(cur);
        continue;
      }

      for (int i = 2, j = 0; i <= m; ++i) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) ++j;
        ne[i] = j;
      }

      for (int i = 1, j = 0; i <= n; ++i) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) ++j;
        if (j == m) {
          cur.push_back(i - j);
          j = ne[j];
        }
      }

      res.push_back(cur);
    }

    return res;
  }
};
