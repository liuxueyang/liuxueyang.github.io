class Solution {
public:
  string convert(string s, int k) {
    if (k == 1) return s;

    int n = s.size(), c = k + (k - 2), w = (n / c + 1) * (k - 1), h = k;
    string r(w, ' ');
    vector<string> g(h, r);

    int x = 0, y = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      g[x][y] = s[i];

      if (flag && x + 1 >= h) {
        flag = false;
      }
      if (!flag && x - 1 < 0) {
        flag = true;
      }

      if (flag) {
        x++;
      } else {
        x--; y++;
      }
    }

    string res;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (!isspace(g[i][j])) {
          res += g[i][j];
        }
      }
    }

    return res;
  }
};
