+++
title = 'LeetCode Contest-377D 转换字符串的最小成本 II'
date = 2023-12-25T07:29:15+08:00
tags = [ "graphs", "dp", "floyd" ]
categories = [ "LeetCode" ]
+++

- [转换字符串的最小成本 II](https://leetcode.cn/problems/minimum-cost-to-convert-string-ii/description/)

边的个数只有 100，点的个数最多有 200，因此可以使用 floyd 求出所有全源最短路。对于原字符串 $s$，设 $dp[i]$ 为前使得 $s[1, i]$ 区间内的字符和 $t[1, i]$ 相等的最小代价，那么有 $dp_i = min(dp_i, dp_{i - len_j} + d[x_j][y_j])$，其中 $len_j$ 为替换的字符串 $x_j$ 的长度，$d[x_j][y_j]$ 为从点 $x_j$ 到 $y_j$ 的最短路，之前使用 floyd 已经求出。所以只需要枚举要替换的字符串的长度即可，题目有点卡常数，暴力枚举长度范围 $[1, 1000]$ 会超时，先统计出 100 条边的所有的长度，这样长度的范围只有 $100$。

```cpp
// Date: Sun Dec 24 17:39:37 2023

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define LN ListNode
#define LNP ListNode *
#define TN TreeNode
#define TNP TreeNode *

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)
#define Rof(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define For1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define Rof1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define ForE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#endif

const int N = 300;
ll d[N][N], dp[1010];

class Solution {
public:
  long long minimumCost(string s, string t, vector<string> &a,
                        vector<string> &b, vector<int> &cost) {
    const ll INF = 0x3f3f3f3f'3f3f3f3f;
    s = " " + s;
    t = " " + t;
    int n = SZ(s), m = SZ(b), idx = 1;
    unordered_map<string, int> vis;

    For(i, 0, m) {
      if (!has(vis, a[i])) {
        vis[a[i]] = idx++;
      }
      if (!has(vis, b[i])) {
        vis[b[i]] = idx++;
      }
    }

    For(i, 1, idx) {
      For(j, 1, idx) {
        if (i == j)
          d[i][j] = 0;
        else
          d[i][j] = INF;
      }
    }

    For(i, 0, m) {
      int x = vis[a[i]], y = vis[b[i]];
      d[x][y] = min(d[x][y], ll(cost[i]));
    }

    For(k, 1, idx) {
      For(i, 1, idx) {
        For(j, 1, idx) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
      }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int i = 1;
    while (i < n && s[i] == t[i]) {
      dp[i] = 0;
      ++i;
    }

    set<int> lens;
    For(i, 0, m) {
      lens.insert(SZ(a[i]));
    }

    For(i, 1, n) {
      if (s[i] == t[i])
        dp[i] = min(dp[i], dp[i - 1]);

      for (auto j : lens) {
        if (j > i) break;

        string s1 = s.substr(i - j + 1, j), s2 = t.substr(i - j + 1, j);
        if (has(vis, s1) && has(vis, s2)) {
          int x = vis[s1], y = vis[s2];
          dp[i] = min(dp[i], dp[i - j] + d[x][y]);
        }
      }
    }

    if (dp[n - 1] == INF)
      return -1;
    return dp[n - 1];
  }
};
```
