// Date: Tue May 24 20:57:52 2022

#include <bits/stdc++.h>

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

const int N = 1010;
int a[N], b[N], d[N][N], n, m;

int main(void)
{
#ifdef _DEBUG
  freopen("136.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &m)) {
    memset(d, 0, sizeof d);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1; i <= m; ++i) scanf("%d", b + i);

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (a[i] == b[j]) {
          d[i][j] = d[i - 1][j - 1] + 1;
        } else {
          d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }

        ans = max(ans, d[i][j]);
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
