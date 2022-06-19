// Date: Tue May 31 23:37:33 2022

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
int n, k;
char a[N];

ll get() {
  ll sum = 0;
  REP(i, 1, n) {
    int c1 = a[i] - '0', c2 = a[i + 1] - '0';
    sum += c1 * 10 + c2;
  }
  return sum;
}

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    scanf("%s", a + 1);
    if (k && a[n-1] > a[n]) {
      swap(a[n-1], a[n]);
      k--;
    }

    if (a[n] == '0') {
      int p = -1;
      PER1(i, 1, n - 1) {
        if (a[i] == '1') {
          p = i;
          break;
        }
      }

      if (p != -1) {
        int need = n - p;
        if (need <= k) {
          swap(a[n], a[p]);
          k -= need;
        }
      }
    }

    if (a[1] == '0') {
      int p = -1;
      REP1(i, 2, n) {
        if (a[i] == '1') {
          p = i;
          break;
        }
      }
      if (p != -1 && p != n) {
        int need = p - 1;
        if (need <= k) {
          swap(a[p], a[1]);
          k -= need;
        }
      }
    }

    ll sum = get();
    printf("%lld\n", sum);
  }

  return 0;
}

