// Date: Fri Jun  3 00:15:33 2022

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

#define REP(i, a, b) for (int i = int(a); i < (b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= (a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= (b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= (a); --i)
#define REPE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())

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

class Solution {
public:
  vector<VI> g, dis, st;
  int n, m;

  bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  int minimumObstacles(vector<vector<int>>& _g) {
    g = _g;
    n = g.size(), m = g[0].size();
    dis = vector<VI> (n, VI(m, INF));
    st = vector<VI> (n, VI(m, 0));

    queue<PII> q;
    q.push({0, 0});
    st[0][0] = 1;
    dis[0][0] = 0;

    while (nonempty(q)) {
      auto t = q.front(); q.pop();
      int x = t.first, y = t.second;
      st[x][y] = 0;

      for (int i = 0; i < 4; ++i) {
        int x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (check(x1, y1)) {
          int tmp = dis[x][y] + g[x1][y1];
          if (tmp < dis[x1][y1]) {
            dis[x1][y1] = tmp;
            if (!st[x1][y1]) {
              st[x1][y1] = 1;
              q.push({x1, y1});
            }
          }
        }
      }
    }

    return dis[n - 1][m - 1];
  }
};
