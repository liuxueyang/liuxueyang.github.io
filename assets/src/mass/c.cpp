// Date: Mon Aug  1 12:59:36 2022

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

const ll N = 2e8 + 1e5, M = 1e7;

ll primes[M];
int cnt;
bool st[N];

void get_primes_range(ll a, ll b) {
  ll top = sqrt(b);
  memset(st, false, sizeof st);
  st[0] = st[1] = true;
  cnt = 0;

  for (ll i = 2; i <= top; ++i) {
    if (!st[i]) {
      primes[cnt++] = i;
      for (ll j = i * i; j <= top; j += i) {
        st[j] = true;
      }
    }
  }

  memset(st, false, sizeof st);
  for (int i = 0; i < cnt; ++i) {
    ll x = primes[i];
    for (ll j = max(x * x, (a + x - 1) / x * x); j <= b; j += x) {
      st[j - a] = true;
    }
  }

  if (a == 1) st[0] = true;
}

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll n = 1e8;
  ll start = n * log(n) + n * (log(log(n)) - 1), end1 = n * log(n) + n * log(log(n));

  get_primes_range(start, end1);

  ll res = 1;
  for (ll i = start; i <= end1; ++i) {
    if (!st[i - start]) {
      // printf("%lld (%lld)\n", i, i - start);
      res = i;
      // break;
    }

    // if (!st[i - start] && i == 2038074743) {
    //   printf("%lld (%lld)\n", i, i - start);
    //   break;
    // }
  }

  printf("%lld\n", res);
  puts("");

  return 0;
}
