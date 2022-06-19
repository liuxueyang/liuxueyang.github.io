// Date: Sat Jun  4 19:04:48 2022

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

const int N = 2010;
PII gh1, gh2, a[N];
ll b[N];
int n;


int main(void)
{
#ifdef _DEBUG
  freopen("b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int x1, y1, x2, y2;
  while (~scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2)) {
    gh1 = {x1, y1}, gh2 = {x2, y2};
    REP1(i, 1, n) {
      int x, y; scanf("%d%d", &x, &y); a[i] = {x, y};
    }

    vector<ll> b1(1, 0), b2(1, 0);
    REP1(i, 1, n) {
      ll h1 = a[i].first - gh1.first, h2 = a[i].second - gh1.second;
      ll h12 = h1 * h1 + h2 * h2;

      debug3(h1, h2, h12);

      ll h3 = a[i].first - gh2.first, h4 = a[i].second - gh2.second;
      ll h34 = h3 * h3 + h4 * h4;

      b1.push_back(h12);
      b2.pb(h34);
    }

    ll res = INF;
    REP1(i, 1, n) {
      debug2(i, b1[i]);

      ll r1 = b1[i], r2 = -1;
      REP1(j, 1, n) {
        if (i == j) continue;
        if (b1[j] <= r1) continue;
        r2 = max(r2, b2[j]);
      }

      debug2(r1, r2);
      if (r2 != -1)
        res = min(res, r1 + r2);
      else res = min(r1, res);
    }
    printf("%lld\n", res);
  }

  return 0;
}
