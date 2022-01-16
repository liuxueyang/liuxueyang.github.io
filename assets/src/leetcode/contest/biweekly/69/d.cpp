// Date: Sat Jan 15 18:45:30 2022

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
  int n, m;
  vector<VI> pg;
  vector<vector<bool>> vis;

  bool possibleToStamp(vector<vector<int>>& g, int n1, int m1) {
    n = g.size();
    m = g[0].size();

    pg = vector<VI> (n + 1, VI(m + 1, 0));
    vis = vector<vector<bool>> (n + 1, vector<bool> (m + 1, false));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int i1 = i + 1, j1 = j + 1;
        pg[i1][j1] = pg[i1 - 1][j1] + pg[i1][j1 - 1] - pg[i1 - 1][j1 - 1] + g[i][j];

        if (g[i][j]) vis[i][j] = true;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis[i][j]) continue;
      }
    }
  }
};
