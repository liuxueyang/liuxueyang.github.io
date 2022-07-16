// Date: Thu Jan  6 22:24:51 2022

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
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

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
  string simplifyPath(string a) {
    string cur, res;
    stack<string> st;
    int n = a.size();

    for (int i = 0; i < n; ++i) {
      if (a[i] == '/') {
        if (cur.empty() || cur == ".") {
        } else if (cur == "..") {
          if (!st.empty()) st.pop();
        } else {
          st.push(cur);
        }

        cur = "";
      } else {
        cur += a[i];
      }
    }

    if (cur.empty() || cur == ".") {
    } else if (cur == "..") {
      if (!st.empty()) st.pop();
    } else {
      st.push(cur);
    }

    vector<string> b;
    while (!st.empty()) {
      b.push_back(st.top());
      st.pop();
    }
    reverse(b.begin(), b.end());

    for (auto &x : b) {
      res += "/" + x;
    }

    if (res.empty()) res = "/";

    return res;
  }
};
