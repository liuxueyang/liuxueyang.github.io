// Date: Sun Jun 12 11:23:10 2022

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

class Solution {
public:
  int n, k;
  VI a;

  bool check(int t) {
    VI vis(n, 0), tar(n, 1);
    int k1 = k;

    while (k1--) {
      if (vis == tar) return true;

      int ma = 0, mas = 0;
      REP(i, 0, (1 << n)) {
        int sum = 0, j = i, idx = 0;
        while (j) {
          if ((j & 1) && !vis[idx]) {
            sum += a[idx];
          }
          idx++;
          j /= 2;
        }

        if (sum > ma && sum <= t) {
          ma = sum;
          mas = i;
        }
      }

      int idx = 0;
      while (mas) {
        if (mas & 1) vis[idx] = 1;
        idx++;
        mas /= 2;
      }
    }

    return vis == tar;
  }

  int distributeCookies(vector<int>& _a, int _k) {
    a = _a;
    n = SZ(a);
    k = _k;
    sort(a.begin(), a.end(), greater<int>());

    int l = 1, r = 1e6, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (check(mid)) r = mid;
      else l = mid + 1;
    }

    return r;
  }
};

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  VI a {8, 15, 10, 20, 8};
  Solution b;
  b.distributeCookies(a, 2);

  return 0;
}
