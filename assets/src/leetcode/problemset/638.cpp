// Date: Thu Nov 11 23:50:05 2021

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

class Solution {
public:
  vector<VI> sp;
  VI ne, zeros, pr;
  int n, res;

  bool check(VI &s) {
    for (int i = 0; i < n; ++i) {
      if (s[i] > ne[i]) return false;
    }
    return true;
  }

  void add(VI &s) {
    for (int i = 0; i < n; ++i) ne[i] -= s[i];
  }

  void restore(VI &s) {
    for (int i = 0; i < n; ++i) ne[i] += s[i];
  }

  void dfs(int idx, int cur) {
    if (idx >= sp.size()) {
      if (ne == zeros) {
        res = min(res, cur);
      }
      return;
    }

    dfs(idx + 1, cur);

    if (check(sp[idx])) {
      add(sp[idx]);
      dfs(idx + 1, cur + sp[idx][n]);
      restore(sp[idx]);
    }
  }

  int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    n = price.size();
    pr = price;
    special = sp;
    ne = needs;
    res = INF;
    zeros = VI(n, 0);

    dfs(0, 0);

    return res;
  }
};
