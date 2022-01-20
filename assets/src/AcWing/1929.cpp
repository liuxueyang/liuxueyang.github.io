// Date: Tue Jan 18 22:25:08 2022

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

const int N = 1010;
char a[N][N];
int n, m;

bool check(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y, int k) {
  int x1, y1, idx;
  if (a[x][y] == '/') idx = 3 - k;
  else idx = k ^ 2;

  x1 = x + dir[idx][0], y1 = y + dir[idx][1];

  if (check(x1, y1)) {
    return 1 + dfs(x1, y1, idx);
  } else return 1;
}

int main(void)
{
#ifdef _DEBUG
  freopen("1929.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int res = 1;

    for (int j = 0; j < m; ++j) {
      res = max(res, dfs(0, j, 2));
      res = max(res, dfs(n - 1, j, 3));
    }

    for (int i = 0; i < n; ++i) {
      res = max(res, dfs(i, 0, 0));
      res = max(res, dfs(i, m - 1, 1));
    }

    cout << res << endl;
  }

  return 0;
}
