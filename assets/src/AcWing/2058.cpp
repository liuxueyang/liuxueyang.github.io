// Date: Wed Jan 19 23:59:42 2022

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

ll toint(string &s) {
  int n = s.size();
  ll res {};
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') res <<= 1;
    else res = (res << 1) + 1;
  }
  return res;
}

bool check1(string &s1, string &s2) {
  if (s1.size() != s2.size()) return false;

  int n = s1.size(), cnt {};

  for (int i = 0; i < n; ++i) {
    if (s1[i] != s2[i]) cnt++;
    if (cnt > 1) return false;
  }

  return cnt == 1;
}

string tobase3(ll n) {
  string res;
  while (n) {
    res += ('0' + (n % 3));
    n /= 3;
  }
  reverse(res.begin(), res.end());

  return res;
}

int main(void)
{
#ifdef _DEBUG
  freopen("2058.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  string s1, s2;
  while (cin >> s1 >> s2) {
    int n = s1.size();
    ll res {};

    for (int i = 0; i < n; ++i) {
      string ts = s1;
      if (s1[i] == '0') ts[i] = '1';
      else ts[i] = '0';

      auto y = toint(ts);

      auto y1 = tobase3(y);
      if (check1(y1, s2)) {
        res = y;
        break;
      }
    }

    cout << res << endl;
  }

  return 0;
}
