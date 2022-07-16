// Date: Mon Nov 15 15:42:47 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

#ifdef _DEBUG

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

set<PII> st;
map<PII, int> dis;

class Solution {
public:
  vector<VI> a;
  int n, m;

  void spfa() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) dis[{i, j}] = INF;

    auto s = PII(0, 0);
    st.insert(s);
    dis[s] = 0;

    queue<PII> q;
    q.push(s);

    while (!q.empty()) {
      auto t = q.front();
      q.pop();

      st.erase(t);

      int x = t.first, y = t.second, x1, y1;
      for (int i = 0; i < 4; ++i) {
        x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
          int tmp = max(dis[t], abs(a[x][y] - a[x1][y1]));

          auto t1 = PII(x1, y1);
          if (dis[t1] > tmp) {
            dis[t1] = tmp;
            if (st.find(t1) == st.end()) {
              st.insert(t1);
              q.push(t1);
            }
          }
        }
      }
    }
  }

  void dijkstra() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) dis[{i, j}] = INF;

    auto s = PII(0, 0);
    dis[s] = 0;

    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> q;

    q.push({0, s});

    while (!q.empty()) {
      auto p = q.top();
      q.pop();

      auto t = p.second;
      auto base = p.first;

      if (st.find(t) != st.end()) continue;

      st.insert(t);

      int x = t.first, y = t.second, x1, y1;
      for (int i = 0; i < 4; ++i) {
        x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
          int tmp = max(base, abs(a[x][y] - a[x1][y1]));

          auto t1 = PII(x1, y1);
          if (dis[t1] > tmp) {
            dis[t1] = tmp;
            q.push({tmp, t1});
          }
        }
      }
    }
  }

  int minimumEffortPath(vector<vector<int>>& _a) {
    a = _a;
    n = a.size(), m = a[0].size();
    st.clear();
    dis.clear();

    dijkstra();

    return dis[{n - 1, m - 1}];
  }
};
