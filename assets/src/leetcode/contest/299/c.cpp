// Date: Sun Jun 26 11:14:39 2022

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

const int N = 200010;

struct info {
  ll v;
  ll sum, presum, postsum;
  info()
    :v(0), sum(0), presum(0), postsum(0) {}

  info(ll _v)
    :v(_v), sum(_v), presum(_v), postsum(_v) {}

  info operator + (const info & r) {
    info ans;
    ans.sum = sum + r.sum;
    ans.presum = max(presum, sum + r.presum);
    ans.postsum = max(r.postsum, r.sum + postsum);
    ans.v = max({v, r.v, postsum + r.presum});

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
      seg[id].v = info(a[l]);
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
      seg[id].v = info(v);
    } else {
      int mid = (l + r) / 2, id1 = id * 2, id2 = id1 + 1;
      if (p <= mid) change(id1, l, mid, p, v);
      else change(id2, mid + 1, r, p, v);

      update(id);
    }
  }
};

segtree<int> tree;

class Solution {
public:
  int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
    int n = SZ(a);
    tree.init(n);
    REP1(i, 1, n) tree.a[i] = a[i - 1] - b[i - 1];
    tree.build(1, 1, n);

    ll sum1 = 0, sum2 = 0;
    REP(i, 0, n) sum1 += a[i], sum2 += b[i];
    ll q = tree.query(1, 1, n, 1, n).v;
    ll ans = sum2 + q;

    tree.init(n);
    REP1(i, 1, n) tree.a[i] = b[i - 1] - a[i - 1];
    tree.build(1, 1, n);
    q = tree.query(1, 1, n, 1, n).v;
    ans = max(ans, sum1 + q);

    return ans;
  }
};
