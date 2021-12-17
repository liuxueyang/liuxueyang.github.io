// Date: Sun Dec 12 10:34:50 2021

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

const int N = 1010;
int d1[N][N], d2[N][N];

class Solution {
public:
  long long subArrayRanges(vector<int>& a) {
    int n = a.size();
    ll res = 0;

    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j) {
        if (i == j) {
          d1[i][j] = a[i];
          d2[i][j] = a[i];
        } else {
          d1[i][j] = -INF;
          d2[i][j] = INF;
        }
      }

    for (int k = 2; k <= n; ++k) {
      for (int i = 0; i + k - 1 < n; ++i) {
        int j = i + k - 1;
        d1[i][j] = max(d1[i + 1][j], d1[i][j - 1]);
        d2[i][j] = min(d2[i + 1][j], d2[i][j - 1]);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        res += (d1[i][j] - d2[i][j]);
      }
    }

    return res;
  }
};
