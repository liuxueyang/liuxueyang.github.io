using PII = pair<int, int>;
const int INF = 0x3f3f3f3f;

const int dir[4][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
};

class Solution {
public:
  int minCost(vector<vector<int>>& g) {
    int n = g.size(), m = g[0].size();
    vector<int> dis(m * n, INF), st(m * n, 0);
    priority_queue<PII, vector<PII>, greater<PII>> q;

    dis[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
      auto t = q.top(); q.pop();
      int base = t.first, ver = t.second;
      if (st[ver]) continue;
      st[ver] = 1;

      int x = ver / m, y = ver % m;
      for (int i = 0; i < 4; ++i) {
        int x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
          int tmp = base + (i + 1 != g[x][y]);
          int j = x1 * m + y1;

          if (tmp < dis[j]) {
            dis[j] = tmp;
            q.push({dis[j], j});
          }
        }
      }
    }

    return dis[n * m - 1];
  }
};
