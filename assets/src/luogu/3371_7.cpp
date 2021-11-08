// Date: Mon Nov  8 22:41:19 2021

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

const int N = 10010, M = 500010;
int n, m, h[N], st[N], dis[N];
int idx, e[M], ne[M], w[M];
int s;

void Init() {
  idx = 0;
  memset(dis, 0x3f, sizeof dis);
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa() {
  dis[s] = 0;

  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, s});

  while (!q.empty()) {
    PII t = q.top();
    q.pop();
    int base = t.first, ver = t.second;
    if (st[ver]) continue;
    st[ver] = 1;

    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i], tmp = base + w[i];
      if (tmp < dis[j]) {
        dis[j] = tmp;
        q.push({dis[j], j});
      }
    }
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("3371.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  Init();
  cin >> n >> m >> s;
  while (m --) {
    int a, b, c;
    cin >> a >> b >> c;
    Add(a, b, c);
  }

  spfa();

  for (int i = 1; i <= n; ++i)
    cout << (dis[i] == INF ? (1LL << 31) - 1 : dis[i]) << ' ';

  cout << endl;

  return 0;
}
