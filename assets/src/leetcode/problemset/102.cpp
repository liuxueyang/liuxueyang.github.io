// Date: Fri Oct 29 08:39:01 2021

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

  vector<vector<int>> levelOrder(TreeNode* ro) {
    vector<VI> res;
    queue<PTI> que;

    if (!ro) return res;

    int cur = 1;
    que.push(PTI(ro, 1));
    VI tmp;

    while (!que.empty()) {
      auto t = que.front();
      que.pop();

      if (t.second != cur) {
        res.push_back(tmp);
        tmp.clear();
        cur = t.second;
        tmp.push_back(t.first->val);
      } else {
        tmp.push_back(t.first->val);
      }

      if (t.first->left) que.push(PTI(t.first->left, t.second + 1));
      if (t.first->right) que.push(PTI(t.first->right, t.second + 1));
    }

    if (!tmp.empty()) res.push_back(tmp);

    return res;
  }
};
