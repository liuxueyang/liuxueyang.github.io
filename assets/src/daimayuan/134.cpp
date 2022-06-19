// Date: Tue May 24 20:34:49 2022

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

const int N = 1010, M = 1010;
int n, m, h[N], dis[N];
int e[M], ne[M], w[M], idx;

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(dis, 0x3f, sizeof dis);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int main(void)
{
#ifdef _DEBUG
  freopen("134.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &m)) {
    Init();
    while (m--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      Add(b, a, c);
    }

    dis[n] = 0;
    for (int i = n; i >= 1; --i) {
      for (int j = h[i]; j != -1; j = ne[j]) {
        int k = e[j], tmp = w[j] + dis[i];
        dis[k] = min(dis[k], tmp);
      }
    }

    printf("%d\n", dis[1]);
  }

  return 0;
}
