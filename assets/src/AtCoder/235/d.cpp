// Date: Sat Jan 15 20:16:31 2022

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

int convert(int n) {
  int res = n / 10;
  int x = n % 10;

  n /= 10;

  while (n) {
    x *= 10;
    n /= 10;
  }

  res += x;
  return res;
}

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int a, n;
  while (cin >> a >> n) {
    map<int, int> m;
    int x = 1;
    m[x] = 0;

    queue<PII> q;
    q.push({1, 0});
    int res = -1;

    while (!q.empty()) {
      auto t = q.front();
      q.pop();

      x = t.first;
      int cnt = t.second;

      if (x == n) {
        res = cnt;
        break;
      }

      int x1 = x * a;
      if (m.find(x1) == m.end() && x1 < 1e6) {
        m[x1] = cnt + 1;
        q.push({x1, cnt + 1});
      }

      if (x > 10 && x % 10 != 0) {
        x1 = convert(x);
        if (m.find(x1) == m.end() && x1 < 1e6) {
          m[x1] = cnt + 1;
          q.push({x1, cnt + 1});
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}
