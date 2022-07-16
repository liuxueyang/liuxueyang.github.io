const int INF = 0x3f3f3f3f, N = 500010;

int d[N][4];

class Solution {
public:
  int minSideJumps(vector<int>& a) {
    memset(d, 0x3f, sizeof d);
    int n = a.size();
    d[0][1] = d[0][3] = 1;
    d[0][2] = 0;

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= 3; ++j) {
        if (j == a[i]) continue;

        int x1 = j + 1, y1 = j + 2;
        x1 %= 3; y1 %= 3;
        if (x1 == 0) x1 = 3;
        if (y1 == 0) y1 = 3;

        d[i][j] = min(d[i - 1][j],
                      min(d[i][x1] + 1,
                          min(d[i][j],
                              d[i][y1] + 1)));
      }

      for (int j = 1; j <= 3; ++j) {
        if (j == a[i]) continue;

        int x1 = j + 1, y1 = j + 2;
        x1 %= 3; y1 %= 3;
        if (x1 == 0) x1 = 3;
        if (y1 == 0) y1 = 3;

        d[i][j] = min(d[i - 1][j],
                      min(d[i][x1] + 1,
                          min(d[i][j],
                              d[i][y1] + 1)));
      }
    }

    return min(d[n - 1][1],
               min(d[n - 1][2],
                   d[n - 1][3]));
  }
};
