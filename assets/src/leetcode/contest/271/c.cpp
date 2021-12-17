// Date: Sun Dec 12 10:44:57 2021

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
  int minimumRefill(vector<int>& a, int b, int c) {
    int res {};
    int n = a.size(), i = 0, j = n - 1;
    int curb = b, curc = c;

    for (; i < j; ++i, --j) {
      if (curb >= a[i])
        curb -= a[i];
      else {
        res++;
        curb = b - a[i];
      }

      if (curc >= a[j])
        curc -= a[j];
      else {
        res++;
        curc = c - a[j];
      }
    }

    if (i == j) {
      curb = max(curb, curc);
      if (curb >= a[i]) ;
      else {
        res++;
      }
    }

    return res;
  }
};
