// Date: Tue Jun 21 07:31:15 2022

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

const int N = 110, M = 200010;

int n, m, idx, h[N], st[N], dis[N];
int e[M], ne[M], w[M];

void init() {
  idx = 0;
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
  memset(dis, 0x3f, sizeof dis);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(int s) {
  dis[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q;
  q.push({0, s});

  while (nonempty(q)) {
    auto t = q.top(); q.pop();
    int base = t.f1, ver = t.f2;
    if (st[ver]) continue;
    st[ver] = 1;

    REPE(i, ver) {
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
  freopen("./Mice_and_Maze.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d", &n)) {
    init();
    int start, target;
    scanf("%d%d%d", &start, &target, &m);
    while (m--) {
      int a, b, c; scanf("%d%d%d", &a, &b, &c);
      Add(b, a, c);
    }
    dijkstra(start);
    int res {};
    REP1(i, 1, n) {
      if (dis[i] <= target) res++;
    }
    printf("%d\n", res);
  }

  return 0;
}
