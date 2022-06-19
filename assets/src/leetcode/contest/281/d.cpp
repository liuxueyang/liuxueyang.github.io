// Date: Sun Feb 20 13:09:56 2022

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
int cnt[N];

class Solution {
public:
  long long coutPairs(vector<int>& a, int k) {
    memset(cnt, 0, sizeof cnt);

    for (auto x : a) cnt[x]++;

    for (int i = 1; i < N; ++i) {
      for (int j = i * 2; j < N; j += i)
        cnt[i] += cnt[j];
    }

    ll res {};
    for (auto &x : a) {
      int tmp = cnt[k / gcd(k, x)];
      res += tmp;

      if (ll(x) * x % k == 0) res--;
    }

    res >>= 1;
    return res;
  }

  ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
  }
};
