// Date: Sat May 28 23:33:19 2022

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

const int N = 50010;
vector<PII> a(N);

class BookMyShow {
public:
  int n, m;

  BookMyShow(int _n, int _m) {
    n = _n, m = _m;
    for (int i = 0; i < n; ++i) a[i] = {{0, m - 1}};
  }

  bool check_p(PII &p, int k) {
    int x = p.first, y = p.second;
    return y - x + 1 >= k;
  }

  pair<bool, int> check_row(vector<PII> &v, int k, bool flag) {
    int l = 0, r = v.size() - 1, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (check_p(v[mid])) r = mid;
      else l = mid + 1;
    }

    int pos = -1;

    if (check_p(v[r])) {
      if (flag) {
        pos = v[r].first;
        v[r].first += k;
        if (v[r].first > v[r].second) {
          swap(v[r], v[v.size() - 1]);
          v.pop_back();
        }
        sort(v.begin(), v.end());
      }
      return pair<bool, int>(true, pos);
    }
    return pair<bool, int>(false, pos);
  }

  vector<int> gather(int k, int maxRow) {
    int l = 0, r = maxRow, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (check_row(a[mid], k, false).first) r = mid;
      else l = mid + 1;
    }

    VI res(2, 0);
    if (check_row(a[r], k, false).first) {
      res[0] = r;
      res[1] = check_row(a[r], k ,true).second;
    }
    return res;
  }

  ll check_r(int r, int &k, bool flag) {
    ll res = 0;
    for (auto p : a[r]) {
      res += (p.second - p.first + 1);
    }

    if (flag) {
      for (auto &p : a[r]) {
        int tmp = p.second - p.first + 1;
        if (k > tmp) {
          k -= tmp;
        }
      }
    }
    return res;
  }

  bool check_sc(int k, int maxr) {
    bool flag = false;
    ll sum = 0;
    for (int i = 0; i <= maxr; ++i) {
      ll tmp = check_r(i, k, false);
      sum += tmp;
      if (sum >= k) {
        flag = true;
        break;
      }
    }

    if (flag) {
      for (int i = 0; i <= maxr; ++i) {
        check_r(i, k, true);
      }
    }
  }

  bool scatter(int k, int maxRow) {
    
  }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
