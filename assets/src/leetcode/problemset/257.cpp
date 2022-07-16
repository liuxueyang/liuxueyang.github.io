// Date: Fri Oct 29 15:03:23 2021

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
  VI tmp;
  vector<string> res;

  void con() {
    string r = to_string(tmp[0]);
    for (int i = 1; i < tmp.size(); ++i) {
      r += "->" + to_string(tmp[i]);
    }
    res.push_back(r);
  }

  void dfs(TNP ro) {
    if (!ro) return;
    tmp.push_back(ro->val);

    auto l = ro->left, r = ro->right;
    if (!l && !r) {
      con();
      tmp.pop_back();
      return;
    }

    if (l) {
      dfs(l);
    }
    if (r) dfs(r);

    tmp.pop_back();
  }

  vector<string> binaryTreePaths(TreeNode* ro) {
    res.clear();
    tmp.clear();

    if (!ro) return res;
    dfs(ro);

    return res;
  }
};
