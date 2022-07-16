// Date: Sat Feb 12 10:35:45 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

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
  vector<VI> a;
  int m, n;
  vector<vector<bool>> vis;

  void dfs(int x, int y) {
    int x1, y1;
    vis[x][y] = true;

    for (int i = 0; i < 4; ++i) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] && !vis[x1][y1])
        dfs(x1, y1);
    }
  }

  int numEnclaves(vector<vector<int>>& grid) {
    a = grid;
    n = a.size(), m = a[0].size();
    vis = vector<vector<bool>> (n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && a[i][j] && !vis[i][j])
          dfs(i, j);
      }
    }

    int res {};

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] && !vis[i][j])
          ++res;
      }
    }

    return res;
  }
};
