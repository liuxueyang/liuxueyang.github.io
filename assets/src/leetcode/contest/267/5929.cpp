// Date: Sun Nov 14 11:22:28 2021

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

const int N = 1010;
int fa[N], sz[N];

void Init() {
  for (int i = 0; i < N; ++i) fa[i] = i, sz[i] = 1;
}

int Find(int x) {
  if (x == fa[x]) return fa[x];
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
  unordered_map<int, unordered_set<int>> rest;
  unordered_map<int, unordered_set<int>> fam;

  bool check1(int x, int y) {
    bool flag = false;

    if (rest.find(x) != rest.end()) {
      auto &m = rest[x];
      flag = flag || (m.find(y) != m.end());
    } else if (rest.find(y) != rest.end()) {
      auto &m = rest[y];
      flag = flag || (m.find(x) != m.end());
    }

    return flag;
  }

  bool check2(unordered_set<int> &a, unordered_set<int> &b) {
    for (auto &x : a) {
      for (auto &y : b) {
        if (check1(x, y) || check1(y, x)) return false;
      }
    }

    return true;
  }

  vector<bool> friendRequests(int n, vector<vector<int>>& a, vector<vector<int>>& b) {
    Init();
    rest.clear();
    fam.clear();

    for (auto &v : a) {
      int x = v[0], y = v[1];
      rest[x].insert(y);
      rest[y].insert(x);
    }

    for (int i = 0; i < n; ++i) fam[i].insert(i);

    int m = b.size();
    vector<bool> res(m, false);

    for (int i = 0; i < m; ++i) {
      auto &v = b[i];
      int x = v[0], y = v[1];
      int rx = Find(x), ry = Find(y);

      if (rx == ry) {
        res[i] = true;
        continue;
      }

      if (check2(fam[rx], fam[ry])) {
        Union(x, y);
        rx = Find(x);
        fam[rx].insert(y);
        fam[rx].insert(x);
        res[i] = true;
      } else
        res[i] = false;
    }

    return res;
  }
};
