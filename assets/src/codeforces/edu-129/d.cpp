// Date: Mon May 23 23:23:14 2022

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

VI digits(ull x) {
  set<int> s;
  while (x) {
    int t = x % 10;
    if (t) s.insert(t);
    x /= 10;
  }
  VI res;
  for (auto &i : s) res.push_back(i);
  return res;
}

int leng(ull x) {
  int res {};
  while (x) {
    x /= 10;
    res++;
  }
  return res;
}

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  using PUI = pair<ull, int>;
  ull n, x;
  while (cin >> n >> x) {
    set<ull> vis;
    bool mark = false;
    queue<PUI> q;
    q.push({x, 0});
    vis.insert(x);

    while (!q.empty()) {
      auto t = q.front();
      q.pop();

      ull y = t.first;
      int cnt = t.second, len = leng(y);
      if (len == n) {
        mark = true;
        cout << cnt << "\n";
        break;
      }

      auto dig = digits(y);
      for (auto &i : dig) {
        ull t = y * i;
        if (vis.find(t) != vis.end()) continue;
        vis.insert(t);
        q.push({t, cnt + 1});
      }
    }

    if(!mark) cout << -1 << "\n";
  }

  return 0;
}
