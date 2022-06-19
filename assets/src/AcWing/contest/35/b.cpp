// Date: Sun Jan 23 12:54:53 2022

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

void select(int n, int idx, VI &tmp, vector<VI> &res, int k) {
  if (idx == n) {
    if (tmp.size() == k) {
      res.push_back(tmp);
      return;
    }
    return;
  }

  if (tmp.size() < k) {
    tmp.push_back(idx);
    select(n, idx + 1, tmp, res, k);
    tmp.pop_back();

    select(n, idx + 1, tmp, res, k);
  } else {
    select(n, idx + 1, tmp, res, k);
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("b.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  VI tmp;
  vector<VI> res;
  select(3, 0, tmp, res, 2);

  for (auto &v : res) {
    for (auto &x : v) {
      cout << x << ' ';
    }
    cout << endl;
  }

  return 0;
}
