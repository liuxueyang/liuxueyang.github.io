// Date: Sat Jul  2 19:04:36 2022

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

const int N = 400010;

/*
 *vector<int> alls; // 存储所有待离散化的值
 sort(alls.begin(), alls.end()); // 将所有值排序
 alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

 // 二分求出x对应的离散化的值
 int find(int x) // 找到第一个大于等于x的位置
 {
 int l = 0, r = alls.size() - 1;
 while (l < r)
 {
 int mid = l + r >> 1;
 if (alls[mid] >= x) r = mid;
 else l = mid + 1;
 }
 return r + 1; // 映射到1, 2, ...n
 }

 */

template<class T>
struct BIT {
  T c[N];
  int n;

  void resize(int _n) {
    n = _n;
    memset(c, 0, sizeof c);
  }

  int lowbit(int x) {
    return x & (-x);
  }

  T query(int x) {
    T s = 0;
    assert(x <= n);
    while (x) {
      s = max(c[x], s);
      x -= lowbit(x);
    }
    return s;
  }

  void modify(int x, T d) {
    assert(x != 0);
    while (x <= n) {
      c[x] = max(d, c[x]);
      x += lowbit(x);
    }
  }
};

BIT<int> tree;

int main(void)
{
#ifdef _DEBUG
  freopen("b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  while (~scanf("%d", &n)) {
    VI a(n * 2, 0), b(n, 0);

    REP(i, 0, n) {
      scanf("%d", &b[i]);
      a[i] = b[i];
      a[i + n] = a[i] * 2;
    }

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    unordered_map<int, int> m;
    REP(i, 0, SZ(a)) {
      m[a[i]] = i + 1;
    }

    tree.resize(SZ(a));
    int res = 1;

    PER(i, 0, n) {
      int pos = m[b[i] * 2];
      int tmp = tree.query(pos);
      res = max(res, tmp + 1);
      tree.modify(m[b[i]], tmp + 1);
    }

    printf("%d\n", res);
  }

  return 0;
}
