// Date: Thu Nov 18 09:34:08 2021

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

const int N = 20;
bool vis[N];

class Solution {
public:
  VI a;
  int n, sum, k, cur, ta, cnt;
  VI tmp;
  bool found;

  void dfs(int cur) {
    if (cur == ta) {
      cnt++;
    }
    if (cnt == k) {
      found = true;
      return;
    }
    if (found) return;

    for (int i = 0; i < n; ++i) {
      if (found) return;

      if (vis[i]) continue;

      if (cur + a[i] <= ta) {
        cur = cur + a[i];
        vis[i] = true;

        dfs(cur);

        vis[i] = false;
        if (cur == ta) cnt--;
        cur = cur - a[i];
      }
    }
  }

  bool canPartitionKSubsets(vector<int>& nums, int k_) {
    memset(vis, false, sizeof vis);
    a = nums;
    n = a.size();
    sum = 0;
    found = false;
    for (auto &x : a) sum += x;
    k = k_;
    tmp.clear();
    cnt = 0;

    if (sum % k != 0) return false;
    ta = sum / k;

    for (auto &x : a)
      if (x > ta) return false;

    sort(a.begin(), a.end(), [](const int &x, const int &y) {
      return x >= y;
    });

    dfs(0);

    return found;
  }
};
