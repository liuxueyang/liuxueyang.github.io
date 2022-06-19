// Date: Sat May 28 08:34:18 2022

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

const int N = 200010;
int a[N], b[N][2], stk[N], n, tt;

int main(void)
{
#ifdef _DEBUG
  freopen("508.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i)
      scanf("%d", a + i);

    tt = 0;
    a[0] = a[n + 1] = 0;
    stk[++tt] = 0;

    for (int i = 1; i <= n; ++i) {
      while (tt && a[stk[tt]] >= a[i]) --tt;
      b[i][0] = stk[tt];
      stk[++tt] = i;
    }

    tt = 0;
    stk[++tt] = n + 1;
    for (int i = n; i >= 1; --i) {
      while (tt && a[stk[tt]] >= a[i]) --tt;
      b[i][1] = stk[tt];
      stk[++tt] = i;
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      res = max(res, ll(a[i]) * (b[i][1] - b[i][0] - 1));
    }
    printf("%lld\n", res);
  }

  return 0;
}
