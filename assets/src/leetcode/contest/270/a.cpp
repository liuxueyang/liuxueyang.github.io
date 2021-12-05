// Date: Sun Dec  5 23:26:25 2021

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
  vector<int> findEvenNumbers(vector<int>& a) {
    VI res;
    int n = a.size();
    set<int> s;

    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 != 0) continue;

      for (int j = 0; j < n; ++j) {
        if (i == j) continue;

        for (int k = 0; k < n; ++k) {
          if (k == j || k == i) continue;

          if (a[k] == 0) continue;

          s.insert(a[k] * 100 + a[j] * 10 + a[i]);
        }
      }
    }

    for (auto &x : s) res.push_back(x);
    sort(res.begin(), res.end());

    return res;
  }
};
