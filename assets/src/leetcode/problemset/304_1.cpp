// Date: Tue Nov  2 12:12:32 2021

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

class NumMatrix {
public:
  vector<VI> d, s;
  int n, m;

  NumMatrix(vector<vector<int>>& _m) {
    d = _m;
    n = d.size(); m = d[0].size();

    s = vector<VI>(n + 1, VI(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + d[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int r2, int c2, int r1, int c1) {
    r1++; c1++; r2++; c2++;
    return s[r1][c1] - s[r1][c2 - 1] - s[r2 - 1][c1] + s[r2 - 1][c2 - 1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
