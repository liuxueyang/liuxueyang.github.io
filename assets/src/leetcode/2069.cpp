// Date: Tue Nov 30 23:13:13 2021

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
  {1, 0},
  {0, 1},
  {-1, 0},
  {0, -1},

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

class Robot {
public:
  int width, height, curx, cury, d;

  Robot(int width_, int height_)
    :width(width_), height(height_), curx(0), cury(0), d(0) {

  }

  bool check(int x, int y) {
    return x >= 0 && x < width && y >= 0 && y < height;
  }

  bool check_corner(int x, int y) {
    return (!x && !y) || (x == width - 1 && y == 0) ||
      (x == width - 1 && y == height - 1) ||
      (x == 0 && y == height - 1);
  }

  void step(int n) {
    if (!n) return;

    int tot = (width - 1) * 2 + (height - 1) * 2;
    n %= tot;
    if (!n && check_corner(curx, cury)) {
      d = (d - 1 + 4) % 4;
      return;
    }

    int x = curx, y = cury, x1 = curx, y1 = cury;
    while (n--) {
      x1 = x + dir[d][0];
      y1 = y + dir[d][1];
      while (!check(x1, y1)) {
        d = (d + 1) % 4;
        x1 = x + dir[d][0];
        y1 = y + dir[d][1];
      }

      x = x1;
      y = y1;
    }

    curx = x1;
    cury = y1;
  }

  vector<int> getPos() {
    return VI{curx, cury};
  }

  string getDir() {
    const vector<string> dirs {
      "East", "North", "West", "South",
    };

    return dirs[d];
  }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
