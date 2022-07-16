// Date: Wed Jun  1 23:47:39 2022

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

const int N = 100010;

template<class T>
struct BIT {
  int n;
  T c[N];

  void resize(int _n) {
    n = _n;
    memset(c, 0, sizeof c);
  }

  int lowbit(int x) {
    return x & (-x);
  }

  void modify(int x, ll d) {
    while (x <= n) {
      c[x] += d;
      x += lowbit(x);
    }
  }

  T query(int x) {
    T s = 0;
    while (x) {
      s += c[x];
      x -= lowbit(x);
    }
    return s;
  }
};

BIT<int> c;

class Solution {
public:
  long long goodTriplets(vector<int>& a, vector<int>& b) {
    int n = a.size();
    VI m(n + 1, 0);
    c.resize(n);

    REP(i, 0, n) {
      m[b[i]] = i;
    }
    REP(i, 0, n) {
      a[i] = m[a[i]] + 1;
    }

    ll res = 0;

    REP(i, 0, n) {
      ll l = c.query(a[i]), r = n - a[i] - i + l;
      res += l * r;
      c.modify(a[i], 1);
    }
    return res;
  }
};
