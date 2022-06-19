// Date: Tue May 31 23:19:06 2022

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
int n, a[N], stk[N], tt, d[N], d1[N];
ll p[N], po[N];

struct info {
  ll v;

  info operator + (const info & r) {
    info ans;
    ans.v = max(v, r.v);
    return ans;
  }
};

struct segtree {
  struct Node {
    info v;
  } seg[N * 4];
  vector<ll> a;

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
      seg[id].v = {a[l]};
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

  void change(int id, int l, int r, int p, int v) {
    if (l == r) {
      seg[id].v = {v};
    } else {
      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      if (p <= mid) change(id1, l, mid, p, v);
      else change(id2, mid + 1, r, p, v);

      update(id);
    }
  }
};

segtree t1, t2;

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP1(i, 1, n) scanf("%d", a + i);

    t1.init(n), t2.init(n);

    REP1(i, 1, n) t1.a[i] = t1.a[i - 1] + a[i];
    PER1(i, 1, n) t2.a[i] = t2.a[i + 1] + a[i];

    t1.build(1, 1, n);
    t2.build(1, 1, n);

    a[0] = a[n + 1] = INF;
    tt = 0;

    stk[++tt] = 0;

    REP1(i, 1, n) {
      while (tt && a[stk[tt]] <= a[i]) --tt;
      d[i] = stk[tt];
      stk[++tt] = i;
    }

    tt = 0;
    stk[++tt] = n + 1;
    PER1(i, 1, n) {
      while (tt && a[stk[tt]] <= a[i]) --tt;
      d1[i] = stk[tt];
      stk[++tt] = i;
    }

    bool flag = true;
    REP1(i, 1, n) {
      int l = d[i] + 1, r = d1[i] - 1;
      ll posum = t2.query(1, 1, n, l, i).v - t2.a[i + 1];
      if (posum > a[i]) {
        flag = false; break;
      }

      ll prsum = t1.query(1, 1, n, i, r).v - t1.a[i - 1];
      if (prsum > a[i]) {
        flag = false; break;
      }
    }

    if (!flag) printf("NO\n");
    else printf("YES\n");
  }

  return 0;
}
