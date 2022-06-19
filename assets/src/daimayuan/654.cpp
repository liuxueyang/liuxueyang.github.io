// Date: Thu Jun  2 01:04:51 2022

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

int n, q, a[N];

struct info {
  ll v, c;

  info operator + (const info & r) {
    info ans;

    ans.v = min(v, r.v);
    if (r.v == v) {
      ans.c = r.c + c;
    } else if (r.v < v) {
      ans.c = r.c;
    } else ans.c = c;

    return ans;
  }
};

template<class T>
struct segtree {
  struct Node {
    info v;
  } seg[N * 4];
  vector<T> a;

  void init(int n) {
    a.clear();
    a.resize(n + 10, 0);
  }

  void update(int id) {
    int id1 = id * 2, id2 = id1 + 1;
    seg[id].v = seg[id1].v + seg[id2].v;
  }

  void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
      seg[id].v = {a[l], 1};
    } else {
      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      build(id1, l, mid);
      build(id2, mid + 1, r);

      update(id);
    }
  }

  info query(int id, int l, int r, int ql, int qr) {
    if (ql > qr) return {};

    if (l == ql && r == qr) {
      return seg[id].v;
    }
    int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
    if (qr <= mid) return query(id1, l, mid, ql, qr);
    else if (ql > mid) return query(id2, mid + 1, r, ql, qr);
    else {
      return query(id1, l, mid, ql, mid) + query(id2, mid + 1, r, mid + 1, qr);
    }
  }

  void change(int id, int l, int r, int p, T v) {
    if (l == r) {
      seg[id].v = {v, 1};
    } else {
      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      if (p <= mid) change(id1, l, mid, p, v);
      else change(id2, mid + 1, r, p, v);

      update(id);
    }
  }
};

segtree<ll> t;

int main(void)
{
#ifdef _DEBUG
  freopen("654.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &q)) {
    t.init(n);

    REP1(i, 1, n) {
      scanf("%lld", &t.a[i]);
    }
    t.build(1, 1, n);

    while (q--) {
      int op, x, d, l, r;
      scanf("%d", &op);

      if (op == 1) {
        scanf("%d%d", &x, &d);
        t.change(1, 1, n, x, d);
      } else {
        scanf("%d%d", &l, &r);
        info ans = t.query(1, 1, n, l, r);
        printf("%lld %lld\n", ans.v, ans.c);
      }
    }
  }

  return 0;
}
