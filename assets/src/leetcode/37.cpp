// Date: Sun Oct 31 19:36:06 2021

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

const int N = 15;
bool col[N][N], row[N][N], gr[N][N][N];

class Solution {
public:
  vector<VI> g;
  bool found;

  void dfs(int x, int y) {
    if (found) return;

    if (y == 9) {
      y = 0;
      ++x;
    }

    if (x == 9) {
      found = true;
      return;
    }
    if (g[x][y]) {
      dfs(x, y + 1);
      return;
    }

    for (int m = 1; m <= 9; ++m) {
      if (!row[x][m] && !col[y][m] && !gr[x/3][y/3][m]) {
        row[x][m] = col[y][m] = gr[x/3][y/3][m] = true;
        g[x][y] = m;
        dfs(x, y + 1);
        if (found) return;
        g[x][y] = 0;
        row[x][m] = col[y][m] = gr[x/3][y/3][m] = false;
      }
    }
  }

  void solveSudoku(vector<vector<char>>& _g) {
    memset(col, false, sizeof col);
    memset(row, false, sizeof row);
    memset(gr, false, sizeof gr);
    g = vector<VI>(9, VI(9, 0));
    found = false;

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int x = i * 3, y = j * 3;
        for (int k = 0; k < 3; ++k) {
          for (int m = 0; m < 3; ++m) {
            int x1 = x + k, y1 = y + m;
            if (_g[x1][y1] != '.') {
              int z = g[x1][y1] = _g[x1][y1] - '0';
              row[x1][z] = col[y1][z] = gr[i][j][z] = true;
            }
          }
        }
      }
    }

    dfs(0, 0);

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int x = i * 3, y = j * 3;
        for (int k = 0; k < 3; ++k) {
          for (int m = 0; m < 3; ++m) {
            int x1 = x + k, y1 = y + m;
            _g[x1][y1] = g[x1][y1] + '0';
          }
        }
      }
    }
  }
};
