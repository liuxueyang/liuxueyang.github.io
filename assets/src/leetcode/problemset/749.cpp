// Date: Mon Jul 18 10:10:13 2022

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

#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define REPE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(),(a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

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

const int N = 60;
int vis[N][N], vis1[N][N], b[N][N], a[N][N], st[N][N];

class Solution {
public:
  int m, n, cur;

  bool check(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  void dfs_cnt(int x, int y, int &cnt) {
    vis[x][y] = true;
    b[x][y] = cur;

    REP(i, 0, 4) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];
      if (check(x1, y1) && !vis[x1][y1] && !a[x1][y1]) {
        cnt++;
        vis[x1][y1] = true;
      }

      if (check(x1, y1) && !vis[x1][y1] && a[x1][y1]) dfs(x1, y1, cnt);
    }
  }

  void dfs(int x, int y) {
    vis1[x][y] = true;

    REP(i, 0, 4) {
      int x1 = x + dir[i][0], y1 = y + dir[i][1];

      if (check(x1, y1) && !vis1[x1][y1]) {
        if (!a[x1][y1]) {
          vis1[x1][y1] = true;
          b[x1][y1] = cur;
        } else if (b[x1][y1] == cur) {
          dfs(x1, y1);
        }
      }
    }
  }

  int containVirus(vector<vector<int>>& _a) {
    m = SZ(_a); n = SZ(_a[0]);
    REP(i, 0, m) REP(j, 0, n) a[i][j] = _a[i][j];
    memset(vis, 0, sizeof vis);
    memset(b, 0, sizeof b);

    cur = 1;
  }
};
