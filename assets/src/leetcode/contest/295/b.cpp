// Date: Sun May 29 10:36:31 2022

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
  bool check(string &s) {
    int n = s.size();
    bool flag = true;
    if (n <= 1) return false;

    if (s[0] != '$') return false;
    for (int i = 1; i < n; ++i) {
      if (!isdigit(s[i])) return false;
    }
    return true;
  }

  string get(string &s, int dis) {
    ll res = 0;
    for (int i = 1; i < s.size(); ++i) {
      res = res * 10 + (s[i] - '0');
    }

    double k = double(res) * (1 - double(dis) / 100);
    char a[30] {};
    memset(a, 0, sizeof a);
    sprintf(a, "$%.2lf", k);

    string l(a);
    return l;
  }

  string discountPrices(string s, int d) {
    vector<string> res1;
    int n = s.size();
    string tmp;
    string res;

    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ') {
        if (check(tmp)) {
          tmp = get(tmp, d);
        }
        // res1.push_back(tmp);

        if (res.empty()) {
          res += tmp;
        } else {
          res += ' ';
          res += tmp;
        }
        tmp = "";
      } else {
        tmp += s[i];
      }
    }

    

    if (!tmp.empty()) {
      if (check(tmp)) {
        tmp = get(tmp, d);
      }
      // res1.push_back(tmp);
      if (res.empty()) {
        res += tmp;
      } else {
        res += ' ';
        res += tmp;
      }
    }

    // if (!res1.empty()) res = res1[0];

    // for (int i = 1; i < res1.size(); ++i) {
    //   res += " ";
    //   res += res1[i];
    // }

    return res;
  }
};
