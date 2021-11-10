// Date: Fri Nov  5 23:28:41 2021

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
  int maxFrequency(vector<int>& a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<ll> p(n + 1, 0);
    for (int i = 0; i < n; ++i)
      p[i + 1] = p[i] + a[i];

    int l = 1, r = n, mid;
    while (l < r) {
      mid = (l + r + 1) / 2;

      bool flag = false;
      for (int i = mid; i <= n; ++i) {
        ll ta = ll(mid) * a[i - 1], sum = p[i] - p[i - mid];
        if (ta - sum <= k) {
          flag = true;
          break;
        }
      }

      if (flag) l = mid;
      else r = mid - 1;
    }

    return l;
  }
};