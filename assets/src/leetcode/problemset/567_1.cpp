// Date: Sun Nov  7 10:38:23 2021

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
  bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    VI p1(30, 0), p2(30, 0);

    for (int i = 0; i < n; ++i) p1[s1[i] - 'a']++;

    for (int i = 0, j = 0; j < m; ++j) {
      int idx = s2[j] - 'a';
      p2[idx]++;

      while (i <= j && p2[idx] > p1[idx]) {
        p2[s2[i] - 'a']--;
        ++i;
      }

      if (p1 == p2) return true;
    }

    if (p1 == p2) return true;

    return false;
  }
};
