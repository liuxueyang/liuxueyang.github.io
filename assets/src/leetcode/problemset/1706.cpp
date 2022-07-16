// Date: Thu Feb 24 18:58:14 2022

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
  int n, m;
  VI res;

  bool check(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  int dfs(int state, int x, int y) {
    int box = a[x][y];
    int x1, y1;

    switch (state) {
    case 1:
      y1 = y + 1;
      x1 = x;
      if (check(x1, y1)) {
        if (a[x1][y1] == 1) return dfs(2, x1, y1);
        else return -1;
      } else return -1;
    case 2:
      x1 = x + 1;
      y1 = y;
      if (check(x1, y1)) {
        if (a[x1][y1] == 1) {
          return dfs(1, x1, y1);
        } else {
          return dfs(3, x1, y1);
        }
      } else return y1;
    case 3:
      x1 = x;
      y1 = y - 1;
      if (check(x1, y1)) {
        if (a[x1][y1] == 1) return -1;
        else return dfs(4, x1, y1);
      } else return -1;
    case 4:
      x1 = x + 1;
      y1 = y;
      if (check(x1, y1)) {
        if (a[x1][y1] == 1) return dfs(1, x1, y1);
        else return dfs(3, x1, y1);
      } else return y1;
    }

    return -1;
  }

  vector<int> findBall(vector<vector<int>>& grid) {
    a = grid;
    m = a.size(); n = a[0].size();
    res.resize(n);

    for (int i = 0; i < n; ++i) {
      int state = (a[0][i] == 1 ? 1 : 3);

      res[i] = dfs(state, 0, i);
    }

    return res;
  }
};
