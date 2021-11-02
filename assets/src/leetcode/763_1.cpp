// Date: Tue Nov  2 22:29:05 2021

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
  vector<int> partitionLabels(string s) {
    int n = s.size();
    VI p1(26, n + 1), p2(26, -1);

    for (int i = 0; i < n; ++i) {
      int j = s[i] - 'a';
      p1[j] = min(p1[j], i);
      p2[j] = max(p2[j], i);
    }

    VI res;

    for (int i = 0; i < n; ++i) {
      int c = s[i] - 'a';
      int l = p1[c], r = p2[c];
      int j = i + 1;
      while (j <= r) {
        c = s[j] - 'a';
        r = max(r, p2[c]);
        ++j;
      }

      res.push_back(r - l + 1);
      i = r;
    }

    return res;
  }
};
