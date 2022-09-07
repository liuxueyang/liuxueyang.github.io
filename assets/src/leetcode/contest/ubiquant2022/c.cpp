// Date: Thu Sep  8 02:37:05 2022

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

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

const int N = 100010;
int c2[N], c3[N];

class Solution {
public:
  int getx(int &n, int x) {
    int res {};
    while (n > 1 && n % x == 0) {
      n /= x;
      res++;
    }

    return res;
  }

  int minOperations(vector<int>& a) {
    int n = SZ(a);
    if (n == 1) return 0;

    memset(c2, 0, sizeof c2);
    memset(c3, 0, sizeof c3);

    REP(i, 0, n) {
      c2[i] = getx(a[i], 2);
      c3[i] = getx(a[i], 3);
    }

    REP(i, 1, n) {
      ll gc = gcd(a[i - 1], a[i]);
      if (gc == 1 && a[i - 1] + a[i] > 2) return -1;
    }

    int res {}, m2 = c2[0], m3 = c3[0];

    REP(i, 1, n) {
      m2 = max(m2, c2[i]);
      m3 = max(m3, c3[i]);
    }

    REP(i, 0, n) {
      res += m2 - c2[i];
      res += m3 - c3[i];
    }

    return res;
  }
};
