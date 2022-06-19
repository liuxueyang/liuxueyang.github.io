// Date: Sun Mar 13 11:31:20 2022

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
  int n;
  vector<VI> a;
  vector<vector<bool>> b;
  vector<vector<bool>> vis;
  int res;

  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
  }

  bool check1(vector<bool> &tmp) {
    bool res = true;
    for (auto c : tmp) res = res && c;
    return res;
  }

  void dfs(int x, int y, int val, vector<bool> &tmp) {
    int x1, y1;
    vis[x][y] = true;

    tmp.push_back(b[x][y]);

    for (int i = 0; i < 4; ++i) {
      x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1) && a[x1][y1] == val && !vis[x1][y1]) {
        dfs(x1, y1, val, tmp);
      }
    }
  }

  int digArtifacts(int _n, vector<vector<int>>& a1, vector<vector<int>>& dig) {
    res = 0;
    n = _n;
    a = vector<VI>(n, VI(n, 0));
    b = vector<vector<bool>>(n, vector<bool>(n, false));
    vis = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = 0; i < a1.size(); ++i) {
      int x = a1[i][0], y = a1[i][1], x1 = a1[i][2], y1 = a1[i][3];
      for (int i1 = x; i1 <= x1; ++i1) {
        for (int j1 = y; j1 <= y1; ++j1) {
          a[i1][j1] = i + 1;
        }
      }
    }

    for (auto &v : dig) {
      int x = v[0], y = v[1];
      b[x][y] = true;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (b[i][j] && !vis[i][j]) {
          vector<bool> tmp;
          dfs(i, j, a[i][j], tmp);
          if (check1(tmp)) res++;
        }
      }
    }

    return res;
  }
};
