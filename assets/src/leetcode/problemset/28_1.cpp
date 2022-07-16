// Date: Thu Nov  4 20:22:33 2021

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

const int N = 50010;
char s[N], p[N];
int n, m, ne[N];

class Solution {
public:
  int strStr(string _s, string _p) {
    memset(ne, 0, sizeof ne);
    stringstream ss(_s), ss1(_p);
    ss >> s + 1;
    ss1 >> p + 1;
    n = _s.size(), m = _p.size();
    if (!m) return 0;

    for (int i = 2, j = 0; i <= n; ++i) {
      while (j && p[i] != p[j + 1]) j = ne[j];
      if (p[i] == p[j + 1]) ++j;
      ne[i] = j;
    }

    for (int i = 1, j = 0; i <= n; ++i) {
      while (j && s[i] != p[j + 1]) j = ne[j];
      if (s[i] == p[j + 1]) ++j;
      if (j == m) {
        return i - m;
      }
    }

    return -1;
  }
};
