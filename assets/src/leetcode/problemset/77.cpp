// Date: Sat Oct 30 13:19:28 2021

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

const int N = 25;
bool vis[N];

class Solution {
public:
  vector<VI> res;
  int n, k;
  VI tmp;

  void dfs(int j) {
    if (tmp.size() == k) {
      res.push_back(tmp);
      return;
    }

    for (int i = j; i <= n; ++i) {
      if (!vis[i]) {
        vis[i] = true;
        tmp.push_back(i);

        dfs(i + 1);

        tmp.pop_back();
        vis[i] = false;
      }
    }
  }

  vector<vector<int>> combine(int _n, int _k) {
    n = _n; k = _k;
    memset(vis, false, sizeof vis);

    dfs(1);

    return res;
  }
};
