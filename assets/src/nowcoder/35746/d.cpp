// Date: Sun Jun  5 13:15:20 2022

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
int fa[N], sz[N], n, m, a[N], vx[N];
map<int, int> mcnt[N];
PII cm[N];

void Init() {
  for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1, mcnt[i].clear(), cm[i] = {1, a[i]};
}

int Find(int x) {
  if (x == fa[x]) return x;
  int ro = Find(fa[x]);

  fa[x] = ro;
  return ro;
}

PII getres(PII a, PII b) {
  if (a.f1 == b.f1) return a.f2 < b.f2 ? a : b;
  return a.f1 < b.f1 ? a : b;
}

void Union(int x, int y) {
  int rx = Find(x), ry = Find(y);
  if (rx == ry) return;

  if (sz[rx] < sz[ry]) swap(rx, ry);

  fa[ry] = rx;
  sz[rx] += sz[ry];
  auto rz = getres(cm[rx], cm[ry]);
  cm[rx] = rz;

  for (auto [cnt, x] : mcnt[ry]) {
    mcnt[rx][x] += cnt;
    cm[rx] = getres(cm[rx], {mcnt[rx][x], x});
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &m)) {
    REP1(i, 1, n) scanf("%d", a + i);
    Init();

    while (m--) {
      int op, x, y;
      scanf("%d", &op);
      if (op == 1) {
        scanf("%d%d", &x, &y);
        Union(x, y);
      } else {
        scanf("%d", &x);
        int ro = Find(x);
        printf("%d\n", cm[ro].f2);
      }
    }
  }

  return 0;
}
