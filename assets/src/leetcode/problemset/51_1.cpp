// Date: Wed Nov 17 10:06:38 2021

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

const int N = 11;
bool col[N], d1[N * 2], d2[N * 2];

class Solution {
public:
  int n;
  vector<vector<string>> res;
  vector<string> tmp;

  void dfs(int idx) {
    if (idx == n) {
      res.push_back(tmp);
      return;
    }

    int i = idx;
    for (int j = 0; j < n; ++j) {
      if (!col[j] && !d1[j - i + n] && !d2[j + i]) {
        col[j] = d1[j - i + n] = d2[j + i] = true;
        tmp[i][j] = 'Q';

        dfs(i + 1);

        tmp[i][j] = '.';
        col[j] = d1[j - i + n] = d2[j + i] = false;
      }
    }
  }

  vector<vector<string>> solveNQueens(int _n) {
    n = _n;
    memset(col, false, sizeof col);
    memset(d1, false, sizeof d1);
    memset(d2, false, sizeof d2);
    res.clear();
    tmp = vector<string>(n, string(n, '.'));

    dfs(0);

    return res;
  }
};
