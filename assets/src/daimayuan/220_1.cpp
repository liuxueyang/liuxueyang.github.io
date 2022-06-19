// Date: Tue May 31 12:04:00 2022

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

#define REP(i, a, b) for (int i = int(a); i < (b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= (a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= (b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= (a); --i)

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

const int N = 100010;
int n, d[N], h[N], q[N], hh, tt;
int idx, e[N], ne[N];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(d, 0, sizeof d);
}

void Add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main(void)
{
#ifdef _DEBUG
  freopen("220.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d", &n)) {
    Init();
    int x;
    REP1(i, 2, n) {
      scanf("%d", &x);
      Add(x, i);
    }

    hh = 0, tt = -1;
    REP1(i, 1, n) d[i] = 1;
    q[++tt] = 1;

    while (tt >= hh) {
      int t = q[hh++];
      for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];
        q[++tt] = j;
      }
    }

    PER(i, 0, n) {
      for (int j = h[q[i]]; j != -1; j = ne[j]) {
        int k = e[j];
        d[q[i]] += d[k];
      }
    }

    REP1(i, 1, n) {
      printf("%d%c", d[i], " \n"[i == n]);
    }
  }

  return 0;
}
