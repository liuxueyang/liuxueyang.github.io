// Date: Wed Jan 19 23:09:43 2022

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

int n;

int main(void)
{
#ifdef _DEBUG
  freopen("1934.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> n) {
    priority_queue<int, VI, greater<int>> q1, q2;

    for (int i = 0; i < n; ++i) {
      char ch; int x;
      cin >> ch >> x;

      if (ch == 'T') q1.push(x);
      else q2.push(x);
    }

    double speed = 1, cnt = 1, sumt = 0, dis = 0;

    while (!q1.empty() || !q2.empty()) {
      if (!q1.empty() && !q2.empty()) {
        double delt2 = (q2.top() - dis) / speed;
        double delt1 = q1.top() - sumt;

        if (fabs(delt1 - delt2) < eps) {
          dis = q2.top();
          q1.pop(); q2.pop();
          cnt += 2;
          speed = 1 / cnt;
          sumt += delt1;
        } else if (delt1 > delt2) {
          dis = q2.top();
          q2.pop();
          cnt++;
          speed = 1 / cnt;
          sumt += delt2;
        } else {
          q1.pop();
          dis += delt1 * speed;
          cnt++;
          speed = 1 / cnt;
          sumt += delt1;
        }
      } else if (!q1.empty()) {
        double delt1 = q1.top() - sumt;

        q1.pop();
        dis += delt1 * speed;
        cnt++;
        speed = 1 / cnt;
        sumt += delt1;
      } else if (!q2.empty()) {
        double delt2 = (q2.top() - dis) / speed;

        dis = q2.top();
        q2.pop();
        cnt++;
        speed = 1 / cnt;
        sumt += delt2;
      }
    }

    if (dis < 1000) {
      sumt += (1000 - dis) / speed;
    }

    cout << ll(round(sumt)) << endl;
  }

  return 0;
}
