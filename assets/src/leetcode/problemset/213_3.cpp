// Date: Tue Nov  9 22:37:55 2021

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
int d[N];

class Solution {
public:
  int rob(vector<int>& a) {
    int n = a.size(), res {};
    memset(d, 0, sizeof d);
    if (n == 1) return a[0];

    d[0] = a[0];
    d[1] = max(a[0], a[1]);
    res = d[1];
    for (int i = 2; i < n - 1; ++i) {
      d[i] = max(d[i - 1], d[i - 2] + a[i]);
      res = max(res, d[i]);
    }

    memset(d, 0, sizeof d);
    d[1] = a[1];
    res = max(res, d[1]);
    for (int i = 2; i < n; ++i) {
      d[i] = max(d[i - 1], d[i - 2] + a[i]);
      res = max(res, d[i]);
    }

    return res;
  }
};
