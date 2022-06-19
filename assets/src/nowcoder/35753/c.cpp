// Date: Fri Jun  3 13:25:06 2022

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

struct tag {
  ll d;

  tag operator + (const tag & r) {
    tag ans;
    ans.d = d + r.d;
    return ans;
  }

  bool empty() { return d == 0; }
  void clear() { d = 0; }
};

struct info {
  int len {}, sz {};
  int left[2] {INF, INF}, right[2] {INF, INF}, pre[2] {}, post[2] {};

  info operator + (const info & r) {
    info ans;

    if (sz & 1) {
      
    }

    ans.len = max({len, r.len, polen + r.prlen});
    

    if (le && ri) ans.prlen = len + r.prlen;
    else ans.prlen = prlen;

    if (r.le && r.ri) ans.polen = r.len + polen;
    else ans.polen = r.polen;

    if (le) ans.le = le;
    if (r.ri) ans.ri = r.ri;

    return ans;
  }

  info operator + (const tag & r) {
    return *this;
  }
};

template<class T>
struct segtree {
  struct Node {
    info v;
    tag t;
  } seg[N * 4];
  vector<T> a;

  void init(int n) {
    a.clear();
    a.resize(n + 10, 0);
  }

  PII child(int id) {
    return {id * 2, id * 2 + 1};
  }

  void update(int id) {
    auto ch = child(id);
    seg[id].v = seg[ch.f1].v + seg[ch.second].v;
  }

  void set_tag(int id, tag t) {
    seg[id].t = seg[id].t + t;
    seg[id].v = seg[id].v + t;
  }

  void push_down(int id) {
    if (!seg[id].t.empty()) {
      auto ch = child(id);
      auto t = seg[id].t;
      set_tag(ch.f1, t), set_tag(ch.f2, t);
      seg[id].t.clear();
    }
  }

  void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
      seg[id].v = {};
      seg[id].t = {0};
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

    push_down(id);

    int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
    if (qr <= mid) return query(id1, l, mid, ql, qr);
    else if (ql > mid) return query(id2, mid + 1, r, ql, qr);
    else {
      return query(id1, l, mid, ql, mid) + query(id2, mid + 1, r, mid + 1, qr);
    }
  }

  // modify segment
  void modify(int id, int l, int r, int ql, int qr, tag t) {
    if (ql > qr) return;

    if (l == ql && r == qr) {
      set_tag(id, t);
      return;
    }

    push_down(id);

    int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
    if (qr <= mid) modify(id1, l, mid, ql, qr, t);
    else if (ql > mid) modify(id2, mid + 1, r, ql, qr, t);
    else {
      modify(id1, l, mid, ql, mid, t);
      modify(id2, mid + 1, r, mid + 1, qr, t);
    }

    update(id);
  }

  // chage a point p to value v
  void change(int id, int l, int r, int p, T v) {
    debug2(p, v);
    debug2(l, r);

    if (l == r) {
      if (v > 0)
        seg[id].v = {1, 1, 1, true, true};
      else seg[id].v = {};
    } else {
      push_down(id);

      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      if (p <= mid) change(id1, l, mid, p, v);
      else change(id2, mid + 1, r, p, v);

      update(id);
    }
  }
};

segtree<int> t;
int n;

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int q; scanf("%d", &q);
  n = 1e5;
  t.init(n);
  t.build(1, 1, n);

  while (q--) {
    int op, x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &x);
      t.change(1, 1, n, x, 1);
    } else if (op == 2) {
      scanf("%d", &x);
      t.change(1, 1, n, x, -1);
    } else {
      auto ans = t.query(1, 1, n, 1, n);
      int len = ans.len;
      if (len & 1) len++;
      printf("%d\n", len / 2);
    }
  }

  return 0;
}

