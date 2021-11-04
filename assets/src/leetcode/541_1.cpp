// Date: Wed Nov  3 22:15:31 2021

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
  string reverseStr(string s, int k) {
    int n = s.size(), cur = 0;
    for (int i = 0; i <= n; i += k) {
      if (i && i % (2 * k) == 0) {
        for (int j = i - 2 * k, r = i - k - 1; j < r; ++j, --r)
          swap(s[j], s[r]);
      }
    }

    int rem = n % (2 * k);

    if (!rem) return s;

    if (rem < k) {
      for (int i = n - rem, j = n - 1; i < j; ++i, --j)
        swap(s[i], s[j]);
    } else if (rem >= k && rem < 2 * k) {
      for (int i = n - rem, j = n - rem + k - 1; i < j; ++i, --j)
        swap(s[i], s[j]);
    }

    return s;
  }
};
