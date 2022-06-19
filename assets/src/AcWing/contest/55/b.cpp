// Date: Sat Jun 11 19:07:28 2022

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

const int N = 200010;
int n, m, a[N], b[N], c[N], cnt[N];

void search(int x) {
  int l = 1, r = m, mid;
  while (l < r) {
    mid = (l + r + 1) / 2;
    if (x >= b[mid]) l = mid;
    else r = mid - 1;
  }

  if (b[l] <= x) {
    if (l + 1 <= m) {
      int dis1 = abs(x - b[l]), dis2 = abs(b[l + 1] - x);
      if (dis1 <= dis2) cnt[l]++;
      else cnt[l + 1]++;
    } else {
      cnt[l]++;
    }
  } else {
    cnt[l]++;
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &m)) {
    int ai = 0, bi = 0, t = n + m;
    REP1(i, 1, t) scanf("%d", c + i);
    REP1(i, 1, t) {
      int x; scanf("%d", &x);
      if (x == 1) b[++bi] = c[i];
      else a[++ai] = c[i];
    }
    memset(cnt, 0, sizeof cnt);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    REP1(i, 1, n) {
      search(a[i]);
    }

    REP1(i, 1, m) {
      printf("%d%c", cnt[i], " \n"[i == m]);
    }
  }

  return 0;
}
