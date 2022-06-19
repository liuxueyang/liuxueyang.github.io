// Date: Sat Jun 11 01:57:52 2022

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

const int N = 100010;
char a[N];
int n;

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%s", a + 1)) {
    int c0 {}, c1 {}, c2 {};
    int n = strlen(a + 1), r = 0;

    REP1(i, 1, n) {
      int c = (a[i] - '0') % 3;
      if (!c && (a[i] - '0')) c0++;
      else if (c == 1) c1++;
      else c2++;

      r = (r + c) % 3;
    }

    if (!r) {
      if (!c0) {
        printf("yukari\n"); continue;
      }
      c0--;

      if (c1 == c2 && c0) puts("kou");
      else puts("yukari");
    } else {
      if (r == 1) {
        if (!c1) {
          puts("yukari"); continue;
        }
        c1--;

        if (c1 == c2 && c0) puts("kou");
        else puts("yukari");
      } else {
        if (!c2) {
          puts("yukari"); continue;
        }
        c2--;

        if (c1 == c2 && c0) puts("kou");
        else puts("yukari");
      }
    }
  }

  return 0;
}
