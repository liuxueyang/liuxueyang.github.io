// Date: Fri Feb 25 10:19:32 2022

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
  PII extract(string s) {
    PII res;
    int x {}, y {}, n = s.size();

    bool flag = true;
    int sign = 1;
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        if (s[i] == '-') {
          sign = -1;
        } else {
          x = x * 10 + (s[i] - '0');
        }
      } else {
        if (s[i] == '+') {
          if (flag) {
            flag = false;
            x *= sign;
            sign = 1;
          }
        } else if (s[i] == 'i') {
          y *= sign;
          break;
        } else if (s[i] == '-') {
          sign *= -1;
        } else {
          if (flag) x = x * 10 + (s[i] - '0');
          else y = y * 10 + (s[i] - '0');
        }
      }
    }

    res.first = x;
    res.second = y;
    return res;
  }

  string complexNumberMultiply(string s1, string s2) {
    PII x = extract(s1), y = extract(s2);

    int a0 = x.first, b0 = x.second,
      a1 = y.first, b1 = y.second;
    int a = a0 * a1 - b0 * b1,
      b = a0 * b1 + a1 * b0;

    return to_string(a) + "+" + to_string(b) + "i";
  }
};
