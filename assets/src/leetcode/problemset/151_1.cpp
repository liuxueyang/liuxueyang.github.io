// Date: Wed Nov  3 00:05:08 2021

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
  string reverseWords(string s) {
    int n = s.size(), pre = -1;
    for (int i = 0; i < n; ++i) {
      if (pre == -1 && s[i] == ' ') continue;

      if (s[i] != ' ') s[++pre] = s[i];
      else {
        s[++pre] = s[i++];
        while (i < n && s[i] == ' ') ++i;
        --i;
      }
    }

    if (s[pre] == ' ') --pre;

    s = s.substr(0, pre + 1);
    n = pre + 1;

    for (int i = 0, j = n - 1; i < j; ++i, --j)
      swap(s[i], s[j]);

    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ') continue;

      int j = i;
      while (j < n && s[j] != ' ') {
        ++j;
      }

      for (int k1 = i, k2 = j - 1; k1 < k2; ++k1, --k2)
        swap(s[k1], s[k2]);

      i = j - 1;
    }

    return s;
  }
};
