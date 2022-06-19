// Date: Tue Jun  7 23:20:37 2022

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

const int N = 200010;
int k, a[N], n, tc;

int main(void)
{
#ifdef _DEBUG
  freopen("e.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  scanf("%d", &tc);
  while (tc--) {
    scanf("%d%d", &n, &k);
    REP1(i, 1, n) scanf("%d", a + i);

    ll sum = 0;
    map<int, int> m;

    REP1(i, 1, n) {
      sum += a[i] / k;
      a[i] %= k;
      if (a[i])
        m[a[i]]++;
    }
    debug1(sum);

    REP1(i, 1, k - 1) {
      if (has(m, i)) {
        int j = k - i, cnt = m[i];

        debug2(i, cnt);

        REP1(s, j, k - 1) {
          if (i == s) continue;

          if (has(m, s)) {
            int cnt1 = min(cnt, m[s]);

            cnt -= cnt1;
            m[i] -= cnt1;

            m[s] -= cnt1;
            debug3(i, s, cnt1);
            sum += cnt1;
            if (!m[s]) {
              m.erase(s);
            }

            if (!cnt) {
              m.erase(i);
              break;
            }
          }
        }
      }
    }

    REP1(i, 1, k - 1) {
      if (has(m, i)) {
        int cnt = m[i];
        if (cnt >= 2 && (i + i) >= k) {
          sum += (cnt / 2);
        }
      }
    }

    printf("%lld\n", sum);
  }

  return 0;
}
