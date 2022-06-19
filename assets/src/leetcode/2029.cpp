// Date: Thu Jan 20 07:52:21 2022

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
  VI cnt;

  bool dfs(int k, int sum, int c0, int c1, int c2) {
    if (c0 + c1 + c2 == 0) {
      return false;
    }

    bool res;

    if (k & 1) {
      res = true;
      switch (sum) {
      case 0:
        if (c1) res = res && dfs(k + 1, sum + 1, c0, c1 - 1, c2);
        if (c2) res = res && dfs(k + 1, sum + 2, c0, c1, c2 - 1);
        break;
      case 1:
        if (c0) res = res && dfs(k + 1, sum, c0 - 1, c1, c2);
        if (c1) res = res && dfs(k + 1, sum + 1, c0, c1 - 1, c2);
        break;
      case 2:
        if (c0) res = res && dfs(k + 1, sum, c0 - 1, c1, c2);
        if (c2) res = res && dfs(k + 1, (sum + 2) % 3, c0, c1, c2 - 1);
        break;
      }
    } else {
      res = false;
      switch (sum) {
      case 0:
        if (c1) res |= dfs(k + 1, sum + 1, c0, c1 - 1, c2);
        if (c2) res |= dfs(k + 1, sum + 2, c0, c1, c2 - 1);
        break;
      case 1:
        if (c0) res |= dfs(k + 1, sum, c0 - 1, c1, c2);
        if (c1) res |= dfs(k + 1, sum + 1, c0, c1 - 1, c2);
        break;
      case 2:
        if (c0) res |= dfs(k + 1, sum, c0 - 1, c1, c2);
        if (c2) res |= dfs(k + 1, (sum + 2) % 3, c0, c1, c2 - 1);
        break;
      }
    }

    return res;
  }

  bool stoneGameIX(vector<int>& a) {
    cnt = VI(3, 0);
    for (auto &x : a) cnt[x % 3]++;

    return dfs(0, 0, cnt[0], cnt[1], cnt[2]);
  }
};
