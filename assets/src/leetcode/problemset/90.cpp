// Date: Sat Oct 30 16:52:54 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

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

typedef ListNode LN;
typedef LN* LNP;
typedef TreeNode TN;
typedef TN* TNP;

class Solution {
public:
  VI tmp, a;
  int n;
  vector<VI> res;

  void dfs(int idx) {
    if (idx == n) {
      res.push_back(tmp);
      return;
    }

    int cnt = 1;
    for (int i = idx + 1; i < n; ++i) {
      if (a[i] == a[i - 1]) { ++cnt; }
      else break;
    }

    for (int i = 0; i < cnt; ++i) {
      tmp.push_back(a[idx]);
      dfs(idx + cnt);
    }
    for (int i = 0; i < cnt; ++i) tmp.pop_back();

    dfs(idx + cnt);
  }

  vector<vector<int>> subsetsWithDup(vector<int>& _a) {
    a = _a; n = a.size();
    sort(a.begin(), a.end());
    dfs(0);

    return res;
  }
};
