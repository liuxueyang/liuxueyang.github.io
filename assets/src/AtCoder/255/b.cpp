// Date: Sat Jun 11 20:59:42 2022

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

const int N = 1010;
int a[N], n, k;
PII b[N];
bool vis[N];

double dist(PII &a, PII &b) {
  int x1 = a.f1, y1 = a.f2, x2 = b.f1, y2 = b.f2;
  double dx = x1 - x2, dy = y1 - y2;
  return dx * dx + dy * dy;
}

bool check(double len) {
  memset(vis, false, sizeof vis);
  REP1(i, 1, k) vis[a[i]] = true;
  len = len * len;

  REP1(i, 1, n) {
    if (vis[i]) continue;
    bool flag = false;

    REP1(j, 1, k) {
      if ((len - dist(b[i], b[a[j]])) > eps) {
        flag = true;
        // debug3(i, j, sqrt(len));
        break;
      }
    }

    if (!flag) {
      // debug2(i, sqrt(len));
      return false;
    }
  }

  return true;
}

int main(void)
{
#ifdef _DEBUG
  freopen("b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &k)) {
    REP1(i, 1, k) scanf("%d", a + i);
    REP1(i, 1, n) {
      int x, y; scanf("%d%d", &x, &y);
      b[i] = {x, y};
    }

    double l = 0.1, r = 1e7, mid;
    while (fabs(r - l) > eps) {
      mid = (l + r) / 2;
      // debug3(l, r, mid);
      if (check(mid)) r = mid;
      else l = mid;
    }

    printf("%.8lf\n", r);
  }

  return 0;
}

