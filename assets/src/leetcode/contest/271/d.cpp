// Date: Sun Dec 12 10:56:03 2021

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

const int N = 200010, M = 200000;
ll p[N], b[N];

class Solution {
public:
  int maxTotalFruits(vector<vector<int>>& a, int startPos, int k) {
    int n = a.size();
    int res {};

    memset(b, 0, sizeof b);
    for (int i = 0; i < n; ++i) {
      b[a[i][0]] = a[i][1];
    }

    memset(p, 0, sizeof p);
    for (int i = 0; i < N - 1; ++i) {
      p[i + 1] = p[i] + b[i];
    }

    startPos++;
    for (int x = 0; 2 * x <= k; ++x) {
      int y = k - 2 * x;

      int l = startPos - 2 * x, r = min(startPos + y, M + 1);

      if (l <= 0) break;

      res = max(res, int(p[r] - p[l - 1]));
    }

    for (int x = 0; x <= k; ++x) {
      int y = (k - x) / 2;
      int l = startPos - x, r = min(startPos + y, M + 1);

      if (l <= 0) break;

      res = max(res, int(p[r] - p[l - 1]));
    }

    return res;
  }
};
