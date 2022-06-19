// Date: Tue May 31 19:42:58 2022

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

const int N = 510, M = 510;
int n, m, d[N][N][2], h[N], a[N];
int idx, e[M], ne[M];

void Init() {
  idx = 0;
  memset(d, 0, sizeof d);
  memset(h, -1, sizeof h);
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int x) {
  d[x][1][1] = a[x];

  REP1(j, 1, m) {
    REPE(i, x) {
      int k = e[i];
      dfs(k);
      d[x][j][0] = max(d[k][j][0], d[k][j][1]);
      d[x][j][1] = max(d[k][j - 1][0] + a[x], d[x][j][1]);
    }
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("219.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &m)) {
    int x;
    REP1(i, 2, n) {
      scanf("%d", &x); Add(x, i);
    }

    REP1(i, 1, n) scanf("%d")
  }

  return 0;
}
