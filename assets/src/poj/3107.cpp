// Date: Fri Nov  5 01:05:06 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>

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
typedef vector<int> VI;
typedef pair<int, int> PII;

#define LN ListNode
#define LNP ListNode*
#define TN TreeNode
#define TNP TreeNode*

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

const int N = 50010, M = N * 2;
int idx, n, h[N];
int e[M], ne[M];
bool st[N];
int ans, res[N], cnt;

void Init() {
  idx = cnt = 0;
  memset(h, -1, sizeof h);
  memset(st, false, sizeof st);
  ans = INF;
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
  st[u] = true;
  int sum = 1, ma = 0;
  for (int i = h[u]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      int tmp = dfs(j);
      sum += tmp;
      ma = max(ma, tmp);
    }
  }

  ma = max(ma, n - sum);
  if (ma < ans) {
    ans = ma;
    cnt = 0;
    res[cnt++] = u;
  } else if (ma == ans) {
    res[cnt++] = u;
  }

  return sum;
}

int main(void)
{
#ifdef _DEBUG
  freopen("3107.in", "r", stdin);
#endif
  // std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  scanf("%d", &n);
  // cin >> n;
  Init();
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    // cin >> a >> b;
    scanf("%d%d", &a, &b);
    Add(a, b); Add(b, a);
  }
  dfs(1);
  sort(res, res + cnt);
  for (int i = 0; i < cnt; ++i) {
    // if (i) cout << ' ' << res[i];
    // else cout << res[i];
    if (i) printf(" %d", res[i]);
    else printf("%d", res[i]);
  }
  puts("");
  // cout << endl;

  return 0;
}
