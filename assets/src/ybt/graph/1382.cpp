// Date: Sun Feb  6 23:51:57 2022

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

const int N = 100010, M = 500010 * 2;
int idx, dis[N], st[N], h[N], n, m;
int e[M], ne[M], w[M];

void Init() {
  idx = 0;
  memset(dis, 0x3f, sizeof dis);
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
}

void Add(int a, int b, int c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int spfa() {
  dis[1] = 0;
  st[1] = 1;
  queue<int> q({1});

  while (!q.empty()) {
    auto t = q.front(); q.pop();
    st[t] = 0;

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i], tmp = dis[t] + w[i];
      if (tmp < dis[j]) {
        dis[j] = tmp;
        if (!st[j]) {
          st[j] = 1;
          q.push(j);
        }
      }
    }
  }

  return dis[n];
}

int main(void)
{
#ifdef _DEBUG
  freopen("1382.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> n >> m) {
    Init();

    map<PII, int> edge;
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;

      auto t = PII(a, b);
      if (edge.find(t) == edge.end()) {
        edge[t] = c;
      } else {
        if (edge[t] > c) edge[t] = c;
      }
    }

    for (auto &p : edge) {
      auto t = p.first;
      auto c = p.second;
      auto a = t.first, b = t.second;

      Add(a, b, c);
      Add(b, a, c);
    }

    cout << spfa() << endl;
  }

  return 0;
}
