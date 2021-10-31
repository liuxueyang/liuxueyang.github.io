 // Date: Sun Oct 31 23:21:58 2021

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

const int N = 1010;
int d[N][N][2], d1[N][N][2];

class Solution {
public:
  int wiggleMaxLength(vector<int>& a) {
    int n = a.size(), res {};
    memset(d, 0, sizeof d);
    memset(d1, 0, sizeof d1);

    for (int i = 0; i < n; ++i) {
      d[i][i][0] = d[i][i][1] = 1;
      d1[i][i][0] = d1[i][i][1] = a[i];
    }

    for (int k = 2; k <= n; ++k) {
      for (int i = 0; i + k - 1 < n; ++i) {
        int j = i + k - 1;

        if (a[j] > d1[i][j - 1][1]) {
          if (d[i][j - 1][1] + 1 > d[i][j][0]) {
            d[i][j][0] = d[i][j - 1][1] + 1;
            d1[i][j][0] = a[j];
          } else if (d[i][j - 1][1] + 1 == d[i][j][0]) {
            d1[i][j][0] = max(d1[i][j][0], a[j]);
          }
        }
        if (a[j] < d1[i][j - 1][0]) {
          if (d[i][j - 1][0] + 1 > d[i][j][1]) {
            d[i][j][1] = d[i][j - 1][0] + 1;
            d1[i][j][1] = a[j];
          } else if (d[i][j - 1][0] + 1 == d[i][j][1]) {
            d1[i][j][1] = min(d1[i][j][1], a[j]);
          }
        }

        res = max(res, max(d[i][j][0],
                           d[i][j][1]));

        printf("(%d, %d) = %d %d\n", i, j, d[i][j][0], d[i][j][1]);
      }
    }

    return res;
  }
};
