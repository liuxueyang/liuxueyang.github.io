// Date: Sat Oct 30 13:43:15 2021

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

const vector<string> m {
  "", "", "abc", "def", "ghi",
  "jkl", "mno", "pqrs", "tuv",
  "wxyz",
};
const int N = 30;
bool vis[N];

class Solution {
public:
  string a;
  string tmp;
  vector<string> res;
  int n;

  void dfs(int idx) {
    if (idx == n) {
      if (!tmp.empty())
        res.push_back(tmp);
      return;
    }

    auto cur = m[a[idx] - '0'];
    for (auto &c : cur) {
      vis[c - 'a'] = true;
      tmp.push_back(c);

      dfs(idx + 1);

      tmp.pop_back();
      vis[c - 'a'] = false;
    }
  }

  vector<string> letterCombinations(string _a) {
    a = _a;
    n = a.size();
    memset(vis, false, sizeof vis);

    dfs(0);

    return res;
  }
};
