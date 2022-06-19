// Date: Sat Feb 19 20:13:36 2022

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
  {1, 2}, {1, -2},
  {-1, 2}, {-1, -2},
  {2, 1}, {2, -1},
  {-2, 1}, {-2, -1},
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

set<PII> gene(PII p) {
  int x = p.first, y = p.second;
  set<PII> res;

  for (int i = 0; i < 8; ++i) {
    int x1 = x + dir[i][0], y1 = y + dir[i][1];
    res.insert(PII(x1, y1));
  }

  return res;
}

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int x1, y1, x2, y2;
  while (cin >> x1 >> y1 >> x2 >> y2) {
    auto s1 = gene(PII(x1, y1)), s2 = gene(PII(x2, y2));

    bool mark = false;
    for (auto &p : s1) {
      if (s2.find(p) != s2.end()) {
        mark = true;
        break;
      }
    }

    cout << (mark ? "Yes" : "No") << "\n";
  }

  return 0;
}
