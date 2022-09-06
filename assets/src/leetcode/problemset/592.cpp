// Date: Wed Jul 27 09:18:45 2022

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

ll lct(ll a, ll b) {
  ll g = gcd(a, b);
  return a * b / g;
}

class Solution {
public:
  string fractionAddition(string a) {
    ll x = 0, y = 0;
    int sign = 1, start = 0;

    if (a[0] == '+') {
      sign = 1;
      start = 4;
      x = a[1] - '0', y = a[3] - '0';
    } else if (a[0] == '-') {
      sign = -1;
      start = 4;
      x = a[1] - '0', y = a[3] - '0';
    } else {
      sign = 1;
      start = 3;
      x = a[0] - '0', y = a[2] - '0';
    }

    x *= sign;

    REP(i, start, SZ(a)) {
      if (a[i] == '+') sign = 1;
      else sign = -1;

      int x1 = a[i + 1] - '0', y1 = a[i + 3] - '0';

      x1 *= sign;
      ll c = lct(y1, y);
      x *= c / y;
      x1 *= c / y1;

      x += x1;
      y = c;

      ll g1 = gcd(abs(x), abs(y));
      x /= g1; y /= g1;

      i += 3;
    }

    return to_string(x) + "/" + to_string(y);
  }
};
