// Date: Fri Jun  3 20:24:42 2022

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

struct info {
  ull v;

  info operator + (const info & r) {
    info ans;
    ans.v = max(v, r.v);
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

  void change(int id, int l, int r, int p, T v) {
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

segtree<ull> t;
ull b[N], n;
int m;

int main(void)
{
#ifdef _DEBUG
  freopen("e.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d", &m)) {
    t.init(m);
    REP1(i, 1, m) {
      scanf("%llu%llu", &t.a[i], &b[i]);
    }
    scanf("%llu", &n);
    t.build(1, 1, m);

    ull res {};
    REP1(i, 1, m) {
      ull max_a = 0;
      if (i > 1) {
        auto q = t.query(1, 1, m, 1, i - 1);
        max_a = q.v + 1;
      }
      ull left = max(n * b[i], max_a), right = min(t.a[i], (n + 1) * b[i]);

      debug3(i, left, right);
      if(right > left) {
        res += (right - left);
        if (!left) res--;
      }
    }

    printf("%llu\n", res);
  }

  return 0;
}
