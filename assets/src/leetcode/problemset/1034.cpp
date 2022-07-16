// Date: Tue Dec  7 08:07:23 2021

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

class Solution {
public:
  vector<VI> g;
  int row, col, color, cur;
  int n, m;
  vector<VI> vis;

  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  void dfs(int x, int y) {
    int x1, y1;
    vis[x][y] = 1;

    for (int i = 0; i < 4; ++i) {
      x1 = x + dir[i][0];
      y1 = y + dir[i][1];

      if (!check(x1, y1)) {
        g[x][y] = color;
      } else {
        if (vis[x1][y1]) continue;

        if (g[x1][y1] != cur) {
          g[x][y] = color;
        } else {
          dfs(x1, y1);
        }
      }
    }
  }

  vector<vector<int>> colorBorder(vector<vector<int>>& g_, int row_, int col_, int color_) {
    g = g_;

    n = g.size(), m = g[0].size();
    vis = vector<VI> (n, VI(m, 0));
    row = row_, col = col_, color = color_;
    cur = g[row][col];
    vis[row][col] = 1;

    dfs(row, col);

    return g;
  }
};
