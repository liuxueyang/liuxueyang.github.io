// Date: Tue Nov  9 23:30:07 2021

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

const int N = 100010;
int d1[N], d2[N];

class Solution {
public:
  int getMaxLen(vector<int>& a) {
    int n = a.size(), res {};

    memset(d1, 0, sizeof d1);
    memset(d2, 0, sizeof d2);

    if (a[0] > 0) d1[0] = 1;
    else if (a[0] < 0) d2[0] = 1;

    res = d1[0];

    for (int i = 1; i < n; ++i) {
      if (a[i] > 0) {
        d1[i] = d1[i - 1] + 1;

        if (d2[i - 1])
          d2[i] = d2[i - 1] + 1;
      } else if (a[i] < 0) {
        if (d2[i - 1])
          d1[i] = d2[i - 1] + 1;

        d2[i] = d1[i - 1] + 1;
      }

      res = max(res, d1[i]);
    }

    return res;
  }
};
