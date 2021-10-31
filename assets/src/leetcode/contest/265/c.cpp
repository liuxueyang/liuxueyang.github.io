// Date: Sun Oct 31 10:56:59 2021

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

const int N = 1010, M = 10010;
int d[N];
bool vis[N][M];

class Solution {
public:
  VI a;
  int st, g, res, n;

  bool check(int x) {
    return x >= 0 && x <= 1000;
  }

  void dfs(int cur, int t) {
    if (vis[cur][t]) return;

    int base = d[cur];
    vis[cur][base] = true;

    for (int i = 0; i < n; ++i) {
      int ne1 = cur + a[i], ne2 = cur - a[i], ne3 = cur ^ a[i], base1 = base + 1;

      if (ne1 == g || ne2 == g || ne3 == g) {
        res = min(base1, res);
        return;
      }

      if (check(ne1) && base1 < d[ne1]) {
        d[ne1] = base1;
        dfs(ne1, base1);
      }
      if (check(ne2) && base1 < d[ne2]) {
        d[ne2] = base1;
        dfs(ne2, base1);
      }
      if (check(ne3) && base1 < d[ne3]) {
        d[ne3] = base1;
        dfs(ne3, base1);
      }
    }
  }

  int minimumOperations(vector<int>& _a, int _st, int _g) {
    a = _a; st = _st; g = _g;
    n = a.size();
    memset(vis, false, sizeof vis);
    memset(d, INF, sizeof d);
    res = INF;

    d[st] = 0;
    dfs(st, 0);

    if (res == INF) return -1;
    return res;
  }
};
