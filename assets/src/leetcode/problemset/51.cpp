// Date: Sat Oct 30 17:09:18 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

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

typedef ListNode LN;
typedef LN* LNP;
typedef TreeNode TN;
typedef TN* TNP;

const int N = 15;
bool vis[N], d[2 * N], d1[2 * N];

class Solution {
public:
  int n;
  vector<vector<string>> res;
  vector<string> tmp;

  void dfs(int r) {
    if (r == n) {
      res.push_back(tmp);
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (!vis[j] && !d[j + r] && !d1[j - r + n]) {
        vis[j] = d[j + r] = d1[j - r + n] = true;
        tmp[r][j] = 'Q';

        dfs(r + 1);

        tmp[r][j] = '.';
        vis[j] = d[j + r] = d1[j - r + n] = false;
      }
    }
  }

  vector<vector<string>> solveNQueens(int _n) {
    memset(d1, false, sizeof d1);
    memset(d, false, sizeof d);
    memset(vis, false, sizeof vis);
    n = _n;
    tmp = vector<string>(n, string(n, '.'));
    dfs(0);

    return res;
  }
};
