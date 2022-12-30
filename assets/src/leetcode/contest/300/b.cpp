// Date: Sun Jul  3 10:48:41 2022

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1},
  {1, 0},
  {0, -1},
  {-1, 0},
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

const int N = 100010;
int a[N], idx;

class Solution {
public:
  int m, n;
  vector<VI> res;
  vector<vector<bool>> vis;

  bool check(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
  }

  void dfs(int x, int y, int id, int curd) {
    res[x][y] = a[id++];
    vis[x][y] = true;

    if (id == idx) return;

    int x1, y1;
    REP(i, 0, 4) {
      int i1 = (curd + i) % 4;

      x1 = x + dir[i1][0], y1 = y + dir[i1][1];
      if (check(x1, y1) && !vis[x1][y1]) {
        dfs(x1, y1, id, i1);
        break;
      }
    }
  }

  vector<vector<int>> spiralMatrix(int m_, int n_, ListNode* r) {
    m = m_;
    n = n_;

    idx = 0;
    LNP r1 = r;
    while (r1) {
      a[idx++] = r1->val;
      r1 = r1->next;
    }

    res = vector<VI> (m, VI(n, -1));
    vis = vector<vector<bool>> (m, vector<bool>(n, false));

    dfs(0, 0, 0, 0);
    return res;
  }
};
