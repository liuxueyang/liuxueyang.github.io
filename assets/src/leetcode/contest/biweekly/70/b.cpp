// Date: Sat Jan 22 22:35:28 2022

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

class Solution {
public:
  VI a;
  int n, low, high;

  bool valid(int x) {
    if (x < low) return -1;
    else if (x > high) return 1;
    return 0;
  }

  int check(int start) {
    int x = start;
    int tmp = valid(x);
    if (tmp) return tmp;

    for (int i = 0; i < n; ++i) {
      x += a[i];
      tmp = valid(x);
      if (tmp) return tmp;
    }

    return 0;
  }

  int numberOfArrays(vector<int>& _a, int _low, int _high) {
    n = _a.size();
    a = _a; low = _low, high = _high;

    int l = low, r = high, mid;
    while (l < r) {
      mid = (l + r + 1) / 2;
      int tmp = check(mid);

      if (tmp == 0) l = mid;
      else if (tmp > 0) r = mid - 1;
      else l = mid + 1;
    }

    int right = l;
    if (check(right)) return 0;

    l = low, r = high;
    while (l < r) {
      mid = (l + r) / 2;
      int tmp = check(mid);

      if (tmp == 0) r = mid;
      else if (tmp > 0) r = mid - 1;
      else l = mid + 1;
    }

    int left = r;

    return right - left + 1;
  }
};
