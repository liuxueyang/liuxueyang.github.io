// Date: Sat Nov  6 11:17:38 2021

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
  VI a;
  int D, n;

  bool check(int w) {
    int cnt {};
    for (int i = 0; i < n; ++i) {
      int j = i, sum {};
      while (j < n && sum + a[j] <= w) {
        sum += a[j];
        ++j;
      }
      cnt++;
      if (j < n && a[j] > w) return false;
      if (cnt > D) return false;
      i = j - 1;
    }
    return true;
  }

  int shipWithinDays(vector<int>& _a, int _D) {
    a = _a;
    D = _D;
    n = a.size();

    int l = 1, r = 3e7 + 10, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (check(mid)) r = mid;
      else l = mid + 1;
    }
    return r;
  }
};
