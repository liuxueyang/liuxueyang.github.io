// Date: Mon Jul 11 10:17:05 2022

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

const int N = 100010;
int pre[2][N],  post[2][N];

class Solution {
public:
  bool canChange(string a, string b) {
    memset(pre, 0, sizeof pre);
    memset(post, 0, sizeof post);

    int n = SZ(a);
    REP1(i, 1, n) {
      pre[0][i] = pre[0][i - 1];
      pre[1][i] = pre[1][i - 1];

      if (a[i - 1] == 'L') pre[0][i]++;
      else if (a[i - 1] == 'R') pre[0][i] = 0;

      if (b[i - 1] == 'L') pre[1][i]++;
      else if (b[i - 1] == 'R') pre[1][i] = 0;

      if (pre[1][i] < pre[0][i]) return false;
    }

    PER1(i, 1, n) {
      post[0][i] = post[0][i + 1];
      post[1][i] = post[1][i + 1];

      if (a[i - 1] == 'R') post[0][i]++;
      else if (a[i - 1] == 'L') post[0][i] = 0;

      if (b[i - 1] == 'R') post[1][i]++;
      else if (b[i - 1] == 'L') post[1][i] = 0;

      if (post[1][i] < post[0][i]) return false;
    }

    VI c1(2, 0), c2(2, 0);
    REP(i, 0, n) {
      if (a[i] == 'L') c1[0]++;
      else if (a[i] == 'R') c1[1]++;

      if (b[i] == 'L') c2[0]++;
      else if (b[i] == 'R') c2[1]++;
    }

    if (c1 != c2) return false;

    return true;
  }
};
