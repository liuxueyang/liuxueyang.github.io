// Date: Wed Nov  3 23:46:52 2021

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

const int N = 20010;
int stk[N];

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& a) {
    int n = a.size(), tt = 0, m = n * 2;
    VI b(m, 0), b1(m, 0), res(n, 0);
    for (int i = 0; i < n; ++i) b[i] = b[i + n] = a[i];

    for (int i = m - 1; i >= 0; --i) {
      if (!tt) {
        stk[++tt] = i;
        b1[i] = -1;
      } else {
        while (tt && b[i] >= b[stk[tt]]) --tt;
        if (tt) b1[i] = stk[tt];
        else b1[i] = -1;
        stk[++tt] = i;
      }
    }

    for (int i = 0; i < n; ++i) {
      int pos = b1[i];
      if (pos == -1) res[i] = pos;
      else res[i] = b[pos];
    }

    return res;
  }
};
