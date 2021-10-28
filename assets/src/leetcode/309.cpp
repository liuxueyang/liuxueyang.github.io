// Date: Thu Oct 28 17:12:02 2021

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

class Solution {
public:
  int maxProfit(vector<int>& a) {
    int n = a.size();
    vector<VI> d(n, VI(2, 0));

    d[0][1] = -a[0];
    for (int i = 1; i < n; ++i) {
      d[i][0] = max(d[i - 1][1] + a[i], d[i - 1][0]);
      if (i >= 2)
        d[i][1] = max(d[i - 2][0] - a[i], d[i - 1][1]);
      else d[i][1] = max(-a[i], d[i - 1][1]);
    }

    return max(d[n - 1][0], 0);
  }
};
