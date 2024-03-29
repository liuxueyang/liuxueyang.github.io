// Date: Fri Nov  5 10:11:31 2021

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
  vector<int> searchRange(vector<int>& a, int t) {
    int n = a.size(), l, r, mid;
    VI res {-1, -1};
    if (!n) return res;

    l = 0, r = n - 1;
    while (l < r) {
      mid = (l + r) / 2;
      if (a[mid] >= t) r = mid;
      else l = mid + 1;
    }

    if (a[r] != t) return res;
    res[0] = r;

    l = 0, r = n - 1;
    while (l < r) {
      mid = (l + r + 1) / 2;
      if (a[mid] <= t) l = mid;
      else r = mid - 1;
    }
    res[1] = l;

    return res;
  }
};
