// Date: Sun Jun  5 23:28:26 2022

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
int n, tc, a[N];

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    REP1(i, 1, n) scanf("%d", a + i);
    bool flag = false;

    REP(i, 0, 32) {
      VI pos;
      int k = (1 << i);
      REP1(j, 1, n) {
        if (a[j] & k) {
          pos.pb(j);
        }
      }

      if (pos.size() >= 2) {
        flag = true;
        printf("YES\n%d\n", int(pos.size()));

        int pre = 0;
        REP(j, 0, pos.size() - 1) {
          printf("%d %d\n", pre + 1, pos[j]);
          pre = pos[j];
        }
        printf("%d %d\n", pos[pos.size()-2] + 1, n);

        break;
      }
    }

    if (!flag) printf("NO\n");
  }

  return 0;
}
