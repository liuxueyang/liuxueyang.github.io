// Date: Fri Nov 12 11:07:31 2021

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
  TNP find_max(TNP ro) {
    if (!ro) return ro;
    auto r = ro->right;
    if (r) return find_max(r);
    else return ro;
  }

  TNP find_min(TNP ro) {
    if (!ro) return ro;
    auto l = ro->left;
    if (l) return find_min(l);
    return ro;
  }

  TreeNode* deleteNode(TreeNode* ro, int key) {
    if (!ro) return ro;

    auto x = ro->val;
    auto l = ro->left, r = ro->right;

    if (key < x) {
      ro->left = deleteNode(l, key);
    } else if (key > x) {
      ro->right = deleteNode(r, key);
    } else {
      if (!l && !r) {
        delete ro;
        ro = nullptr;
      } else if (l) {
        auto m = find_max(l);
        ro->val = m->val;
        ro->left = deleteNode(l, m->val);
      } else {
        auto m = find_min(r);
        ro->val = m->val;
        ro->right = deleteNode(r, m->val);
      }
    }

    return ro;
  }
};
