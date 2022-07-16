// Date: Thu Nov 11 11:32:33 2021

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

const string a[] = {
  "", "", "abc", "def",
  "ghi", "jkl", "mno",
  "pqrs", "tuv", "wxyz",
};

class Solution {
public:
  vector<string> res;
  string d;
  int n;

  void dfs(string cur, int idx) {
    if (idx == n) {
      res.push_back(cur);
      return;
    }

    int i = d[idx] - '0';
    for (auto &c : a[i]) {
      dfs(cur + c, idx + 1);
    }
  }

  vector<string> letterCombinations(string _d) {
    res = vector<string> {};
    d = _d;
    n = d.size();

    if (!n) return res;

    dfs("", 0);

    return res;
  }
};
