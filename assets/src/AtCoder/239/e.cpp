// Date: Sun Feb 20 18:37:59 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

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

const int N = 100010, M = 2 * N;

int val[N];
int h[N];
int e[M], ne[M], idx;
VI num[N];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  for (int i = 0; i < N; ++i) num[i] = VI{};
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int s, int parent) {
  num[s].push_back(val[s]);

  for (int i = h[s]; i != -1; i = ne[i]) {
    int j = e[i];
    if (j == parent) continue;

    dfs(j, s);

    for (auto k : num[j]) num[s].push_back(k);
  }

  sort(num[s].begin(), num[s].end(), greater<int>());
  num[s].resize(20);
}

int main(void)
{
#ifdef _DEBUG
  freopen("e.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, q;
  while (cin >> n >> q) {
    Init();
    for (int i = 1; i <= n; ++i) cin >> val[i];
    for (int i = 0; i < n - 1; ++i) {
      int a, b; cin >> a >> b;
      Add(a, b); Add(b, a);
    }

    dfs(1, 0);

    while (q--) {
      int v, k;
      cin >> v >> k;
      cout << num[v][k - 1] << "\n";
    }
  }

  return 0;
}
