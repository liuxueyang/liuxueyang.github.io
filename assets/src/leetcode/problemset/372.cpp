// Date: Tue Dec  7 09:52:54 2021

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

class Solution {
public:
  VI div(VI &a, int b) {
    VI c;
    ll t = 0;

    for (int i = int(a.size()) - 1; i >= 0; --i) {
      t = t * 10 + a[i];
      c.push_back(t / b);
      t %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && !c.back()) c.pop_back();

    return c;
  }

  bool zero(VI &a) {
    return a.size() == 1 && a[0] == 0;
  }

  bool odd(VI &a) {
    return a.size() > 0 && (a[0] % 2 != 0);
  }

  ll qmi(ll a, VI &n,  int m) {
    if (m == 1 || a == 0) return 0;
    ll res = 1;

    while (!zero(n)) {
      if (odd(n)) res = res * a % m;
      a = a * a % m;
      n = div(n, 2);
    }

    return res;
  }

  int superPow(int a, vector<int>& b) {
    reverse(b.begin(), b.end());

    return qmi(a, b, 1337);
  }
};
