// Date: Wed May 25 08:53:57 2022

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

const int N = 200010;
VI q[N];
int hh, tt;
int x, k;

VI tovec(int a) {
  VI c;
  while (a) {
    c.push_back(a % 10);
    a /= 10;
  }
  return c;
}

void printv(VI &a) {
  int n = a.size() - 1;
  for (int i = n; i >= 0; --i) cout << a[i];
  cout << '\n';
}

VI add(VI &a, int b) {
  VI c;
  int t = b;
  int n = a.size();

  for (int i = 0; i < n; ++i) {
    t += a[i];
    c.push_back(t % 10);
    t /= 10;
  }

  if (t) c.push_back(t);
  while (c.size() > 1 && !c.back()) c.pop_back();
  return c;
}

VI mul(VI &a, int b) {
  VI c;
  int t = 0;
  int n = a.size();

  for (int i = 0; i < n; ++i) {
    t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }

  if (t) c.push_back(t);
  while (c.size() > 1 && !c.back()) c.pop_back();
  return c;
}

int main(void)
{
#ifdef _DEBUG
  freopen("56.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> x >> k) {
    hh = 0, tt = -1;
    q[++tt] = tovec(x);

    while (k--) {
      auto y = q[hh++];
      printv(y);
      auto y1 = mul(y, 2);
      q[++tt] = y1;
      q[++tt] = add(y1, 1);
    }
  }

  return 0;
}
