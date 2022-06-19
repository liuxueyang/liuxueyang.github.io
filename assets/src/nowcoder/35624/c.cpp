// Date: Sun May 29 12:30:13 2022

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
char a[N][N];
int n, vis[N][N], m;

bool check(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int &cnt) {
  int x1, y1;
  vis[x][y] = 1;
  // printf("x=%d, y=%d\n", x, y);

  for (int i = 0; i < 4; ++i) {
    x1 = x + dir[i][0], y1 = y + dir[i][1];
    if (check(x1, y1) && !vis[x1][y1]) {
      if (a[x1][y1] == '*') {
        cnt++;
        dfs(x1, y1, cnt);
      } else if (a[x1][y1] == '.') dfs(x1, y1, cnt);
    }
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; ++i) {
      scanf("%s", a[i]);
    }

    memset(vis, 0, sizeof vis);

    VI res;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis[i][j]) continue;

        int cnt = 0;
        if (a[i][j] == '.') {
          dfs(i, j, cnt);
        } else if (a[i][j] == '*') {
          cnt++;
          dfs(i, j, cnt);
        }

        res.push_back(cnt);
      }
    }

    sort(res.begin(), res.end(), greater<int>());
    int ans = 0;
    if (!res.empty()) ans = res[0];
    if (res.size() >= 2) ans += res[1];

    printf("%d\n", ans);
  }

  return 0;
}
