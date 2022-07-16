// Date: Sat Jul  2 20:07:48 2022

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

const int N = 20;

char a[N][N];
int n;

int valid(int x) {
  if (x >= 1 && x <= n) return x;
  if (x == 0) return n;
  if (x == n + 1) return 1;
  return -1;
}

int main(void)
{
#ifdef _DEBUG
  freopen("b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d", &n)) {
    memset(a, 0, sizeof a);

    REP1(i, 1, n) {
      scanf("%s", a[i] + 1);
    }

    // REP1(i, 1, n) {
    //   printf("%s\n", a[i] + 1);
    // }

    ll res = 0;

    int ma = -1;
    REP1(i, 1, n) {
      REP1(j, 1, n) {
        ma = max(ma, a[i][j] - '0');
      }
    }

    ll tmp;
    REP1(i, 1, n) {
      REP1(j, 1, n) {
        if (ma != a[i][j] - '0') continue;

        REP1(k, 0, 8) {
          int n1 = n - 1, i2 = i, j2 = j;
          tmp = ma;

          while (n1--) {
            int i1 = valid(i2 + dir[k][0]), j1 = valid(j2 + dir[k][1]);
            tmp = tmp * 10 + (a[i1][j1] - '0');
            i2 = i1, j2 = j1;
          }

          res = max(res, tmp);
        }
      }
    }

    printf("%lld\n", res);
  }

  return 0;
}
