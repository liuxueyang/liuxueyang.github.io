// Date: Sat Jun  4 21:14:22 2022

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
ll a[N];

ll prime_facto(ll n) {
  ll ans = n;
  map<ll, int> res;
  for (ll i = 2; i <= n / i; ++i) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n > 1) res[n]++;

  for (auto p : res) {
    int x = p.f1, cnt = p.f2;
    if (cnt % 2 == 0) {
      while (cnt--) ans /= x;
    }
  }

  return ans;
}

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  while (~scanf("%d", &n)) {
    ll res = 0;
    if (n == 1) {
      printf("1\n"); continue;
    }

    map<int, int> m;
    REP1(i, 2, n) {
      auto f = prime_facto(i);
      debug2(i, f);
      m[f]++;
    }

    res = n;
    for (auto [f, cnt] : m) {
      if (f == 1) {
        res += cnt * 2;
      } else {
        if (cnt >= 2) {
          debug2(f, cnt);
          res += cnt * (cnt - 1);
        }
      }
    }

    printf("%lld\n", res);
  }

  return 0;
}
