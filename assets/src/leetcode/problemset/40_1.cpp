// Date: Thu Nov 11 15:39:10 2021

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

const int N = 110;
bool st[N];

class Solution {
public:
  VI tmp, a;
  vector<VI> res;
  int n;

  void dfs(int cur, int idx) {
    if (cur == 0) {
      res.push_back(tmp);
      return;
    }
    if (cur < 0) return;
    if (idx >= n) return;

    dfs(cur, idx + 1);
    if (idx && a[idx] == a[idx - 1] && !st[idx - 1]) {
      
    } else {
      st[idx] = true;
      tmp.push_back(a[idx]);

      dfs(cur - a[idx], idx + 1);

      st[idx] = false;
      tmp.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& _a, int t) {
    a = _a;
    n = a.size();
    memset(st, false, sizeof st);
    sort(a.begin(), a.end());

    dfs(t, 0);

    return res;
  }
};
