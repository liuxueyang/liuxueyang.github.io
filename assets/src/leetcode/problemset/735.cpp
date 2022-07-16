// Date: Tue Jan 25 09:37:45 2022

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
  vector<int> asteroidCollision(vector<int>& a) {
    stack<int> s1, s2;
    int n = a.size();

    for (auto &x : a) {
      if (x < 0) {
        bool flag = true;

        while (!s1.empty()) {
          int t = s1.top();
          if (abs(t) < abs(x)) {
            s1.pop();
          } else if (abs(t) == abs(x)) {
            s1.pop();
            flag = false;
            break;
          } else {
            flag = false;
            break;
          }
        }

        if (s1.empty() && flag) s2.push(x);
      } else {
        s1.push(x);
      }
    }

    VI res;
    while (!s2.empty()) {
      res.push_back(s2.top());
      s2.pop();
    }
    reverse(res.begin(), res.end());

    VI b;
    while (!s1.empty()) {
      b.push_back(s1.top());
      s1.pop();
    }
    reverse(b.begin(), b.end());
    for (auto &x : b) res.push_back(x);

    return res;
  }
};
