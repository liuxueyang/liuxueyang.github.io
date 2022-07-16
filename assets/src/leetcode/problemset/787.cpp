// Date: Tue Nov 16 14:22:52 2021

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

struct Edge {
  int a, b, w;
};

const int M = 10010, N = 110;
int dis[N], bak[N], n, ta, m, src;
Edge edges[M];

void Init() {
  memset(dis, 0x3f, sizeof dis);
  dis[src] = 0;
}

int bellman_ford() {
  for (int i = 0; i < n; ++i) {
    memcpy(bak, dis, sizeof dis);
    for (int j = 0; j < m; ++j) {
      int a = edges[j].a, b = edges[j].b, w = edges[j].w;
      dis[b] = min(dis[b], bak[a] + w);
    }
  }

  if (dis[ta] > INF / 2) return -1;
  else return dis[ta];
}

class Solution {
public:
  int findCheapestPrice(int _n, vector<vector<int>>& fli, int _src, int _dst, int _k) {
    src = _src;
    n = _k + 1;
    ta = _dst;
    Init();
    m = fli.size();

    for (int i = 0; i < m; ++i) {
      auto v = fli[i];
      edges[i] = {v[0], v[1], v[2]};
    }

    return bellman_ford();
  }
};
