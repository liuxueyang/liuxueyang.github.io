// Date: Fri Oct 29 16:29:35 2021

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
  VI in, po;
  int n;

  bool check(int x) {
    return x >= 0 && x < n;
  }

  TNP dfs(int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return nullptr;
    if (!check(l1) || !check(r1) || !check(l2) || !check(r2))
      return nullptr;

    int roi = r2;

    TNP ro = new TN(po[roi]);
    if (l1 == r1 || l2 == r2) return ro;

    int mid = -1;

    for (int i = l1; i <= r1; ++i) {
      if (in[i] == po[roi]) {
        mid = i;
        break;
      }
    }

    int leftx = mid - l1;
    auto left = dfs(l1, mid - 1, l2, l2 + leftx - 1);
    auto right = dfs(mid + 1, r1, l2 + leftx, r2 - 1);

    ro->left = left;
    ro->right = right;

    return ro;
  }

  TreeNode* buildTree(vector<int>& _in, vector<int>& _po) {
    in = _in; po = _po;
    n = in.size();
    return dfs(0, n - 1, 0, n - 1);
  }
};
