// Date: Sun Feb 20 10:49:22 2022

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
  string repeatLimitedString(string s, int k) {
    string res;
    using PCI = pair<char, int>;

    priority_queue<PCI> q;
    map<char, int> m;
    for (auto &c : s) m[c]++;

    for (auto &p : m) {
      q.push(PCI{p.first, p.second});
    }

    while (!q.empty()) {
      auto t = q.top();
      q.pop();

      char ch = t.first;
      int cnt = t.second;

      if (!res.empty()) {
        if (res[res.size() - 1] != ch) {
          if (cnt >= k) {
            res += string(k, ch);
            cnt -=k;
          } else {
            res += string(cnt, ch);
            cnt = 0;
          }

          if (cnt) q.push({ch, cnt});
        } else {
          if (!q.empty()) {
            auto t1 = q.top(); q.pop();
            char ch1 = t1.first;
            int cnt1 = t1.second;
            res += string(1, ch1);
            cnt1--;
            if (cnt1) q.push({ch1, cnt1});

            q.push(t);
          } else break;
        }
      } else {
        if (cnt >= k) {
          res += string(k, ch);
          cnt -=k;
        } else {
          res += string(cnt, ch);
          cnt = 0;
        }

        if (cnt) q.push({ch, cnt});
      }
    }

    return res;
  }
};
