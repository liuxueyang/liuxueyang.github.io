// Date: Sat May 28 20:16:46 2022

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

ll gcd(ll a, ll b) {
  return b ? gcd(b, a % b) : a;
}

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll n, a, b;
  while (cin >> n >> a >> b) {
    ll sum0 = (1 + n) * n / 2;
    ll ka = n / a, kb = n/ b;
    ll suma = (1 + ka) * ka / 2 * a;
    ll sumb = (1 + kb) * kb / 2 * b;

    ll c = gcd(a, b);
    c = a * b / c;
    ll kc = n / c;
    ll sumc = (1 + kc) * kc / 2 * c;

    sum0 = sum0 - (suma + sumb - sumc);
    cout << sum0 << '\n';
  }

  return 0;
}
