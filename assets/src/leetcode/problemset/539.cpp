// Date: Tue Jan 18 09:17:47 2022

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
  int convert(string &s) {
    int res {};

    int minute = (s[3] - '0') * 10 + (s[4] - '0');
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    res = hour * 60 + minute;

    return res;
  }

  int findMinDifference(vector<string>& a) {
    int n = a.size();
    VI b;

    for (auto &s : a) {
      int tmp = convert(s);
      b.push_back(tmp);
      b.push_back(tmp + 24 * 60);
    }
    sort(b.begin(), b.end());

    int res = INF;
    for (int i = 1; i < b.size(); ++i) {
      res = min(res, b[i] - b[i - 1]);
    }
    return res;
  }
};
