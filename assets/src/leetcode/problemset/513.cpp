// Date: Fri Oct 29 16:04:46 2021

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int res, de;

  void dfsV1(TNP ro, int h) {
    if (!ro) return;

    auto l = ro->left, r = ro->right;
    if (l && !l->left && !l->right) {
      int lh = h + 1;
      if (lh > de) {
        de = lh;
        res = l->val;
      }
    } else if (l) dfs(l, h + 1);

    if (r && !r->left && !r->right) {
      int rh = h + 1;
      if (rh > de) {
        de = rh;
        res = r->val;
      }
    } else if (r) dfs(r, h + 1);
  }

  int findBottomLeftValueV1(TreeNode* ro) {
    de = 1;
    res = ro->val;

    dfs(ro, 1);

    return res;
  }

  void dfs(TNP ro, int h) {
    if (!ro) return;
    if (h > de) {
      de = h;
      res = ro->val;
    }

    dfs(ro->left, h + 1);
    dfs(ro->right, h + 1);
  }

  int findBottomLeftValue(TreeNode* ro) {
    de = 1;
    res = ro->val;

    dfs(ro, 1);

    return res;
  }
};
