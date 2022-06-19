// Date: Wed Jun  1 01:31:01 2022

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

const int N = 200010;
int n, q;
ll a[N], c[N];

ll lowbit(ll x) {
  return x & (-x);
}

ll query(int x) {
  ll sum = 0;
  for (; x; x -= lowbit(x)) {
    sum += c[x];
  }
  return sum;
}

void modify(int x, ll d) {
  for (; x <= n; x += lowbit(x)) {
    c[x] += d;
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("634.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &q)) {
    memset(a, 0, sizeof a);

    REP1(i, 1, n) {
      scanf("%lld", a + i);
      modify(i, a[i]);
    }

    while (q--) {
      int op, x;
      ll d;
      scanf("%d%d", &op, &x);
      if (op == 1) {
        scanf("%lld", &d);
        ll d1 = d - a[x];
        modify(x, d1);
        a[x] = d;
      } else {
        printf("%lld\n", query(x));
      }
    }
  }

  return 0;
}
