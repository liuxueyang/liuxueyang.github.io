// Date: Fri Nov 19 00:59:13 2021

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

bool vis[10];

class Solution {
public:
  VI tmp;
  vector<VI> res;
  int k, n;

  void dfs(int idx, int cur) {
    if (cur > n) return;

    if (tmp.size() == k) {
      if (cur == n) {
        res.push_back(tmp);
      }
      return;
    }

    for (int i = idx; i <= 9; ++i) {
      if (!vis[i]) {
        vis[i] = true;
        tmp.push_back(i);

        dfs(i + 1, cur + i);

        tmp.pop_back();
        vis[i] = false;
      }
    }
  }

  vector<vector<int>> combinationSum3(int k_, int n_) {
    tmp.clear();
    res.clear();
    k = k_;
    n = n_;
    memset(vis, false, sizeof vis);

    dfs(1, 0);

    return res;
  }
};
