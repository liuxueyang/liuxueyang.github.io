// Date: Thu Nov 11 12:58:06 2021

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

const int N = 10;
bool row[N][N], col[N][N], g[N][N][N];

class Solution {
public:
  vector<vector<char>> a;

  bool dfs(int x, int y) {
    if (y >= 9) {
      y = 0; x++;
    }
    if (x >= 9) return true;

    if (a[x][y] != '.') {
      return dfs(x, y + 1);
    } else {
      for (int i = 1; i <= 9; ++i) {
        if (!row[x][i] && !col[y][i] && !g[x / 3][y / 3][i]) {
          row[x][i] = col[y][i] = g[x / 3][y / 3][i] = true;
          a[x][y] = '0' + i;
          if (dfs(x, y + 1)) {
            return true;
          }
          row[x][i] = col[y][i] = g[x / 3][y / 3][i] = false;
          a[x][y] = '.';
        }
      }
    }

    return false;
  }

  void solveSudoku(vector<vector<char>>& _a) {
    a = _a;
    memset(row, false, sizeof row);
    memset(col, false, sizeof col);
    memset(g, false, sizeof g);

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (a[i][j] != '.') {
          int c = a[i][j] - '0';
          row[i][c] =col[j][c] = g[i / 3][j / 3][c] = true;
        }
      }
    }

    dfs(0, 0);

    _a = a;
  }
};
