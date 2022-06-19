// Date: Sat May 28 18:07:54 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

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

const int N = 1010, M = 510, K = 110;
int n, m, k, d[N][M], w[K], c[K];

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d%d", &n, &m, &k)) {
    for (int i = 1; i <= k; ++i) {
      scanf("%d%d", w + i, c + i);
    }
    memset(d, 0, sizeof d);

    for (int i = 1; i <= k; ++i) {
      for (int j = n; j >= w[i]; --j) {
        for (int s = m; s >= c[i]; --s) {
          d[j][s] = max(d[j][s], d[j - w[i]][s - c[i]] + 1);
        }
      }
    }

    int res = 0, use = INF;
    for (int j = 0; j <= n; ++j) {
      for (int s = 0; s <= m; ++s) {
        res = max(res, d[j][s]);
      }
    }

    for (int j = 0; j <= n; ++j) {
      for (int s = 0; s <= m; ++s) {
        if (d[j][s] == res) use = min(use, s);
      }
    }

    printf("%d %d\n", res, m - use);
  }

  return 0;
}
