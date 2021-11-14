// Date: Sun Nov 14 09:53:12 2021

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

const int N = 30;
int fa[N], sz[N];

void Init() {
  for (int i = 0; i < 26; ++i) fa[i] = i, sz[i] = 1;
}

int Find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
  int rx = Find(x), ry = Find(y);
  if (rx == ry) return;
  fa[ry] = rx;
  sz[rx] += sz[ry];
}

class Solution {
public:
  bool equationsPossible(vector<string>& a) {
    vector<PII> b, c;
    for (auto &s : a) {
      if (s[1] == '=') {
        b.push_back({s[0] - 'a', s[3] - 'a'});
      } else {
        c.push_back({s[0] - 'a', s[3] - 'a'});
      }
    }

    Init();

    for (auto &p : b) {
      Union(p.first, p.second);
    }

    for (auto &p : c) {
      int rx = Find(p.first), ry = Find(p.second);
      if (rx == ry) return false;
    }

    return true;
  }
};
