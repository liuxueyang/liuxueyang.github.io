// Date: Tue Nov  9 23:05:31 2021

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

const int N = 30010;
int d[N];

class Solution {
public:
  int maxSubarraySumCircular(vector<int>& a) {
    int n = a.size(), res = a[0], sum {};
    for (int i = 0; i < n; ++i) d[i] = -INF;
    for (int i = 0; i < n; ++i) sum += a[i];

    d[0] = a[0];
    for (int i = 1; i < n; ++i) {
      d[i] = max(d[i - 1] + a[i], a[i]);
      res = max(d[i], res);
    }

    int ans = a[0];
    memset(d, 0x3f, sizeof d);
    d[0] = a[0];
    for (int i = 1; i < n; ++i) {
      d[i] = min(d[i - 1] + a[i], a[i]);
      ans = min(ans, d[i]);
    }

    if (sum != ans)
      res = max(res, sum - ans);

    return res;
  }
};
