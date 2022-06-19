// Date: Fri Jun  3 19:25:44 2022

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

int x, n;
set<PII> vis;

struct node {
  int a, b, cnt, op;

  bool operator < (const node & rhs) const {
    return cnt < rhs.cnt;
  }

  bool exists() const {
    PII p1 = {a, b}, p2 = {b, a};
    return (has(vis, p1) || has(vis, p2));
  }

  void insert() {
    PII p1 = {a, b}, p2 = {b, a};
    vis.insert(p1); vis.insert(p2);
  }

  bool check() const {
    return a == n || b == n;
  }

  PII id1() {return {a, b};}
  PII id2() { return {b, a}; }

  bool begin() { return cnt == 0 || op == -1; }

  node next(int y) {
    node ans{a, b, cnt + 1, y};

    if (y == 1) {
      ans.a += b;
    } else if (y == 2) {
      ans.b += a;
    } else if (y == 3) {
      ans.a *= x;
    } else {
      ans.b *= x;
    }

    return ans;
  }
};

map<node, node> ppath;

vector<node> path(node cur) {
  vector<node> res;

  while (!cur.begin()) {
    res.pb(cur);
    cur = ppath[cur];
  }
  res.pb(cur);

  reverse(res.begin(), res.end());

  return res;
}

void print_path(vector<node> &ans) {
  printf("%ld\n", ans.size());
  REP(i, 1, ans.size()) {
    int op = ans[i].op;
    debug3(i, ans[i].a, ans[i].b);
    if (op == 1) {
      printf("1 a\n");
    } else if (op == 2) printf("1 b\n");
    else if (op == 3) printf("2 a\n");
    else if (op == 4) printf("2 b\n");
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int tc; scanf("%d", &tc);
  while (tc--) {
    vis.clear();
    ppath.clear();

    scanf("%d%d", &n, &x);

    node start {0, 1, 0, -1};
    queue<node> q;
    q.push(start);
    start.insert();

    while (nonempty(q)) {
      auto t = q.front(); q.pop();

      if (t.check() && t.cnt <= 400) {
        auto res = path(t);
        print_path(res);
        break;
      }

      REP1(i, 1, 4) {
        auto t1 = t.next(i);
        if (t1.a > n || t1.b > n) continue;

        if (!t1.exists() && t1.cnt <= 400) {
          t1.insert();
          q.push(t1);
          ppath[t1] = t;

          debug3(t.a, t.b, i);
          debug1("===");
          debug3(t1.a, t1.b, i);
        }
      }
    }
  }

  return 0;
}
