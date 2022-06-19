// Date: Mon May 23 23:06:34 2022

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

const int N = 110;
int a[N], b[N], n;

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    vector<PII> res;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n - i; ++j) {
        if (a[j] > a[j + 1]) {
          swap(a[j], a[j + 1]);
          swap(b[j], b[j + 1]);
          res.push_back({j, j + 1});
        } else if (a[j] == a[j + 1]) {
          if (b[j] > b[j + 1]) {
            swap(b[j], b[j + 1]);
            res.push_back({j, j + 1});
          }
        }
      }
    }

    bool check = true;
    for (int i = 1; i <= n - 1; ++i) {
      if (b[i] > b[i + 1]) {
        check = false;
        break;
      }
    }

    if (check) {
      cout<<res.size() << "\n";
      for (auto &x : res) cout << x.first << ' ' << x.second << '\n';
    } else cout<<"-1\n";
  }

  return 0;
}
