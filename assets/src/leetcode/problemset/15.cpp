// Date: Wed Nov  3 10:44:18 2021

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
  vector<vector<int>> threeSum(vector<int>& a) {
    sort(a.begin(), a.end());
    vector<VI> res;
    int n = a.size();

    for (int i = 0; i < n; ++i) {
      if (i && a[i] == a[i - 1]) continue;
      int ta = -a[i];
      int j = i + 1, k = n - 1;
      while (j < k) {
        if (a[j] + a[k] == ta) {
          res.push_back(VI{a[i], a[j], a[k]});
          ++j;
          while (j < k && a[j] == a[j - 1]) ++j;
        } else if (a[j] + a[k] > ta) {
          --k;
        } else ++j;
      }
    }

    return res;
  }
};
