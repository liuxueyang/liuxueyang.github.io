// Date: Thu Nov 18 23:40:14 2021

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
  VI tmp;
  vector<VI> res;
  string a;
  int n;

  void dfs(int cur, int idx) {
    if (tmp.size() > 4) return;

    if (idx == n) {
      if (tmp.size() == 4) {
        res.push_back(tmp);
      }
      return;
    }

    printf("cur=%d idx=%d, tmp.size() = %d\n", cur, idx, tmp.size());
    for (int i = 0; i < tmp.size(); ++i) printf("%d ", tmp[i]);
    puts("");

    int cur1 = cur * 10 + (a[idx] - '0');
    if (cur1 == 0) {
      tmp.push_back(cur1);
      dfs(0, idx + 1);
      tmp.pop_back();
    } else {
      if (cur1 > 0 && cur1 <= 255) {
        tmp.push_back(cur1);
        dfs(0, idx + 1);
        tmp.pop_back();

        dfs(cur1, idx + 1);
      }

      if (cur > 0 && cur <= 255) {
        tmp.push_back(cur);
        dfs(a[idx] - '0', idx + 1);
        tmp.pop_back();
      }
    }
  }

  string conver(VI &t) {
    string r;
    for (int i = 0; i < 3; ++i) r = r + to_string(t[i]) + ".";
    r = r + to_string(r[3]);
    return r;
  }

  vector<string> restoreIpAddresses(string s) {
    // TODO:
    res.clear();
    tmp.clear();
    a = s;
    n = a.size();

    dfs(0, 0);

    vector<string> ans;
    for (auto &v : res) {
      ans.push_back(conver(v));
    }

    return ans;
  }
};
