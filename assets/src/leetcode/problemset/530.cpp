// Date: Fri Oct 29 17:50:02 2021

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
  int res, low, high;

  int getmin(TNP ro) {
    if (!ro) return -INF;
    if (!ro->left && !ro->right) return ro->val;
    auto l = ro->left;
    if (!l) return ro->val;
    else return getmin(l);
  }

  int getmax(TNP ro) {
    if (!ro) return INF;
    if (!ro->left && !ro->right) return ro->val;
    auto r = ro->right;
    if (!r) return ro->val;
    else return getmax(r);
  }

  void dfsV1(TNP ro) {
    if (!ro) return;

    auto x = ro->val;
    auto l = ro->left, r = ro->right;
    if (l) {
      auto lx = getmax(l);
      res = min(res, abs(lx - x));
      dfs(l);
    }
    if (r) {
      auto ly = getmin(r);
      res = min(res, abs(ly - x));
      dfs(r);
    }
  }

  int getMinimumDifferenceV1(TreeNode* ro) {
    res = INF;
    dfs(ro);
    return res;
  }

  VI ve;

  void dfsV2(TNP ro) {
    if (!ro) return;
    dfs(ro->left);
    ve.push_back(ro->val);
    dfs(ro->right);
  }

  int getMinimumDifferenceV2(TreeNode* ro) {
    res = INF;
    ve.clear();
    dfs(ro);
    for (int i = 1; i < ve.size(); ++i) {
      res = min(res, abs(ve[i] - ve[i - 1]));
    }
    return res;
  }

  int pre, cur;

  void dfs(TNP ro) {
    if (!ro) return;

    dfs(ro->left);

    cur = ro->val;
    if (pre != -INF) {
      res = min(abs(cur - pre), res);
      pre = cur;
    } else {
      pre = cur;
    }

    dfs(ro->right);
  }

  int getMinimumDifference(TreeNode* ro) {
    res = INF;
    pre = -INF;
    cur = 0;
    dfs(ro);

    return res;
  }
};
