// Date: Sun Jan 30 20:55:24 2022

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

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  string s;
  while (cin >> s) {
    int n = s.size(), i = 0, j = n - 1;

    while (i < n && s[i] == 'a') ++i;
    while (j >= 0 && s[j] == 'a') --j;

    int len1 {}, len2 {};
    if (i) len1 = i;
    if (j != n - 1) len2 = n - j;

    if (i >= j) cout << "Yes\n";
    else if (len1 > len2) {
      cout << "No\n";;
    } else {
      int i1 = i, j1 = j;
      bool flag = true;

      while (i1 < j1) {
        if (s[i1] != s[j1]) {
          flag = false;
          break;
        }
        i1++, j1--;
      }

      if (flag) cout << "Yes\n";
      else cout << "No\n";
    }
  }

  return 0;
}
