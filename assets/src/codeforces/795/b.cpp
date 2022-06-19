// Date: Tue May 31 22:51:28 2022

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
int a[N], n, b[N];

int main(void)
{
#ifdef _DEBUG
  freopen("b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP1(i, 1, n) scanf("%d", a + i);
    map<int, VI> m;
    REP1(i, 1, n) {
      m[a[i]].push_back(i);
    }
    bool flag = true;

    for (auto &p: m) {
      if (p.second.size() == 1) {
        flag = false;
        break;
      }
    }

    if (!flag) {
      printf("-1\n"); continue;
    }

    for (auto p : m) {
      auto v = p.second;
      int sz = v.size();
      REP(i, 0, sz) {
        int j = i + 1;
        if (j == sz) j = 0;

        b[v[i]] = v[j];
      }
    }

    REP1(i, 1, n) {
      printf("%d%c", b[i], " \n"[i == n]);
    }
  }

  return 0;
}
