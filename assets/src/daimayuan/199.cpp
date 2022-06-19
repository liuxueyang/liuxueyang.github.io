// Date: Sun May 29 09:38:32 2022

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

const int N = 510;
int d[N][N], a[N], n, p[N];

int main(void)
{
#ifdef _DEBUG
  freopen("199.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }

    memset(d, 0, sizeof d);
    memset(p, 0, sizeof p);
    for (int i = 1; i <= n; ++i) p[i] = p[i - 1] + a[i];

    for (int k = 2; k <= n; ++k) {
      for (int i = 1; i + k - 1 <= n; ++i) {
        int j = i + k - 1;
        int ans = INF;
        for (int s = i; s < j; ++s) {
          ans = min(ans, d[i][s] + d[s + 1][j] + p[j] - p[i - 1]);
        }
        d[i][j] += ans;
      }
    }

    printf("%d\n", d[1][n]);
  }

  return 0;
}
