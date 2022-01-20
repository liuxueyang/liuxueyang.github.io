// Date: Wed Jan 19 22:27:40 2022

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

const int N = 100010;
PII a[N];
int n, p[N];

int main(void)
{
#ifdef _DEBUG
  freopen("1913.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      int x; char ch;
      cin >> x >> ch;

      if (ch == 'G') a[i] = PII(x, -1);
      else a[i] = PII(x, 1);
    }

    sort(a, a + n);
    memset(p, 0, sizeof p);
    p[0] = a[0].second;

    map<int, int> m;
    m[p[0]] = 0;

    int res {};

    for (int i = 1; i < n; ++i) {
      p[i] = p[i - 1] + a[i].second;
      if (m.find(p[i]) != m.end()) {
        int j = m[p[i]] + 1;
        res = max(res, a[i].first - a[j].first);
      } else {
        m[p[i]] = i;
      }
    }

    int cur = a[0].second, len = 1;

    for (int i = 1; i < n; ++i) {
      if (a[i].second == cur) {
        len++;
        continue;
      } else {
        int j = i - 1, j1 = j - len + 1;
        res = max(res, a[j].first - a[j1].first);

        len = 1;
        cur = a[i].second;
      }
    }

    int j = n - 1, j1 = j - len + 1;
    res = max(res, a[j].first - a[j1].first);

    cout << res << endl;
  }

  return 0;
}
