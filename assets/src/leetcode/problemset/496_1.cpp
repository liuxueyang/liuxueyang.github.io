// Date: Wed Nov 10 10:37:58 2021

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

const int N = 1010;
int stk[N];

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    VI res(n, -1), p(m, -1);
    int tt = 0;

    unordered_map<int, int> pos;
    for (int i = 0; i < m; ++i) {
      pos[b[i]] = i;
    }
    for (int i = m - 1; i >= 0; --i) {
      while (tt && b[i] >= b[stk[tt]]) --tt;
      if (tt) p[i] = b[stk[tt]];
      stk[++tt] = i;
    }

    for (int i = 0; i < n; ++i) {
      res[i] = p[pos[a[i]]];
    }

    return res;
  }
};
