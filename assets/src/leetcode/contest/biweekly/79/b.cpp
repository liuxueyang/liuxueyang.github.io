// Date: Sat May 28 22:51:49 2022

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
  int check(string &s) {
    stringstream ss(s);
    int res = 0;
    string tmp;
    while (ss >> tmp) {
      res++;
    }

    return res;
  }

  string largestWordCount(vector<string>& a, vector<string>& b) {
    int n = a.size();
    VI words(n, 0);
    for (int i = 0; i < n; ++i) {
      words[i] = check(a[i]);
    }

    map<string, int> m;
    for (int i = 0; i < n; ++i) {
      m[b[i]] += words[i];
    }

    int maxn = 0;
    string name;
    for (auto p : m) {
      auto x = p.first;
      auto y = p.second;

      if (y >= maxn) {
        maxn = y;
        if (x >= name) name = x;
      }
    }

    return name;
  }
};
