// Date: Fri Oct 29 08:59:46 2021

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
  using PTI = pair<TNP, int>;

  vector<vector<int>> levelOrderBottom(TreeNode* ro) {
    vector<VI> res;
    if (!ro) return res;

    queue<PTI> que;
    que.push(PTI(ro, 1));
    int cur = 1;
    VI tmp;

    while (!que.empty()) {
      auto t = que.front();
      auto x = t.first;
      auto m = t.second;
      que.pop();

      if (m != cur) {
        res.push_back(tmp);
        tmp.clear();
        cur = m;
        tmp.push_back(x->val);
      } else {
        tmp.push_back(x->val);
      }

      if (x->left) que.push(PTI(x->left, m + 1));
      if (x->right) que.push(PTI(x->right, m + 1));
    }

    if (!tmp.empty()) res.push_back(tmp);

    reverse(res.begin(), res.end());

    return res;
  }
};
