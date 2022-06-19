// Date: Sun May 29 11:06:47 2022

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

const int N = 100010;
int b[N];

class Solution {
public:
  int totalSteps(vector<int>& a) {
    int n = a.size(), res {};
    memset(b, 0, sizeof b);

    int pre = a[0], cnt = 0, cur = -INF, cnt1 = 0;

    for (int i = 1; i < n; ++i) {
      if (a[i] >= pre) {
        res = max(res, cnt);
        pre = a[i];
        cnt = 0;
        cnt1 = 0;

        if (i + 1 < n)
          cur = a[i + 1];
      } else {

        if (a[i] < a[i - 1]) {

          b[i] = 1;
          // if (!cnt) {
          //   cnt++;
          //   b[i] = 1;
          // } else {
          //   b[i] = b[i - 1];
          // }

          cur = a[i];
          
          
        } else {
          // cnt++;
          if (a[i] >= cur) b[i] = max(cnt + 1, b[i - 1] + 1);
          else
            b[i] = b[i - 1] + 1;
          // cur = a[i];
          cnt = b[i];
        }
        
        if (a[i] >= cur) {
          cur = a[i];
          cnt = b[i];
        }
      }
    }

    res = 0;
    for (int i = 1; i < n; ++i) res = max(res, b[i]);
    

    return res;
  }
};
