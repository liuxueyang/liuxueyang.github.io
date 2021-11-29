// Date: Sun Nov 28 11:06:41 2021

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

const int N = 100010;
int fa[N], sz[N], n;

void Init() {
  for (int i = 0; i < n; ++i) {
    fa[i] = i;
    sz[i] = 1;
  }
}

int Find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = Find(fa[x]);
}

void Union(int x, int y) {
  int rx = Find(x), ry = Find(y);
  if (rx == ry) return;
  fa[ry] = rx;
  sz[rx] += sz[ry];
}

vector<int> res;

class Solution {
public:
  vector<int> findAllPeople(int n_, vector<vector<int>>& a, int fp) {
    sort(a.begin(), a.end(), [](const VI &x, const VI &y) {
      return x[2] < y[2];
    });

    n = n_;
    Init();
    Union(0, fp);

    res.clear();
    set<int> s;
    s.insert(fp);
    s.insert(0);

    for (int i = 0; i < a.size(); ++i) {
      int t = a[i][2], r0 = Find(0);
      int j = i + 1;

      Union(a[i][0], a[i][1]);

      while (j < a.size() && a[j][2] == t) {
        int x = a[j][0], y = a[j][1];
        Union(x, y);
        ++j;
      }

      for (int k = i; k < j; ++k) {
        int x = a[k][0], y = a[k][1], rx = Find(x), ry = Find(y), r0 = Find(0);
        if (rx == r0) {
          s.insert(x);
          s.insert(y);
        } else {
          fa[x] = x;
          fa[y] = y;
          sz[x] = 1;
          sz[y] = 1;
        }
      }

      i = j - 1;
    }

    for (auto &x : s) res.push_back(x);

    return res;
  }
};
