// Date: Sat Jan 22 22:59:47 2022

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

struct Item {
  int step, price, x, y;
  Item(int s, int p, int _x, int _y)
    :step(s), price(p), x(_x), y(_y) {}
  // friend bool operator<(const Item &other) const {
  //   if (step > other.step) return true;
  //   else if (price > other.price) return true;
  //   else if (x > other.x) return true;
  //   else if (y > other.y) return true;
  //   return false;
  // }
};

bool operator<(const Item &a, const Item &other) {
  if (a.step < other.step) return true;
  else if (a.price < other.price) return true;
  else if (a.x < other.x) return true;
  else if (a.y < other.y) return true;
  return false;
}

class Solution {
public:
  vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
    vector<VI> res;
    int n = grid.size(), m = grid[0].size();

    auto check = [&](int x, int y) -> bool {
      return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 0;
    };
    auto check_pri = [&](int price) -> bool {
      return price >= pricing[0] && price <= pricing[1];
    };

    priority_queue<Item> pq;

    queue<pair<PII, int>> q;
    q.push({PII(start[0], start[1]), 0});
    set<PII> vis;
    vis.insert({start[0], start[1]});

    int x = start[0], y = start[1];
    if (grid[x][y] != 0 && grid[x][y] != 1 && check_pri(grid[x][y])) {
      pq.push(Item(0, grid[x][y], x, y));
    }

    while (!q.empty()) {
      if (pq.size() >= k) break;

      auto t = q.front(); q.pop();
      auto node = t.first; int step = t.second;

      int x1, y1;
      x = node.first, y = node.second;

      for (int i = 0; i < 4; ++i) {
        x1 = x + dir[i][0], y1 = y + dir[i][1];
        if (check(x1, y1) && vis.find({x1, y1}) == vis.end()) {
          vis.insert({x1, y1});

          q.push({PII(x1, y1), step + 1});

          if (grid[x1][y1] == 1) {
            ;
          } else {
            if (check_pri(grid[x1][y1])) {
              pq.push(Item(step + 1, grid[x1][y1], x1, y1));
              if (pq.size() >= k) break;
            }
          }
        }
      }

      if (pq.size() >= k) break;
    }

    while (!pq.empty()) {
      auto t = pq.top(); pq.pop();
      printf("%d, %d. step=%d, price=%d\n", t.x, t.y, t.step, t.price);
      res.push_back(VI{t.x, t.y});
    }

    return res;
  }
};
