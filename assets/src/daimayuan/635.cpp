// Date: Wed Jun  1 22:00:52 2022

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

template<class T>
struct BIT {
  T c[N];
  int n;

  void resize(int _n) {
    n = _n;
    memset(c, 0, sizeof c);
  }

  int lowbit(int x) {
    return x & (-x);
  }

  T query(int x) {
    T s = 0;
    assert(x <= n);
    while (x) {
      s += c[x];
      x -= lowbit(x);
    }
    return s;
  }

  void modify(int x, T d) {
    assert(x != 0);
    while (x <= n) {
      c[x] += d;
      x += lowbit(x);
    }
  }
};

BIT<ull> d, d1;

int main(void)
{
#ifdef _DEBUG
  freopen("635.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, q;
  while (~scanf("%d%d", &n, &q)) {
    d.resize(n);
    d1.resize(n);

    while (q--) {
      ull op, l, r, x, delta;
      scanf("%llu", &op);
      if (op == 1) {
        scanf("%llu%llu%llu", &l, &r, &delta);

        d.modify(l, delta);
        d.modify(r + 1, -delta);

        d1.modify(l, delta * l);
        d1.modify(r + 1, -delta * (r + 1));
      } else {
        scanf("%llu", &x);
        ull s1 = d.query(x) * (x + 1),
          s2 = d1.query(x);
        printf("%llu\n", s1 - s2);
      }
    }
  }

  return 0;
}
