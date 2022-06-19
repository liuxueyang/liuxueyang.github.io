// Date: Sun May 29 13:42:24 2022

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

const int N = 50;
char d[N];

bool check(string &s) {
  int n = s.size();
  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) return false;
  }

  for (int i = 1; i < (n + 1) / 2; ++i) {
    if (s[i] <= s[i - 1]) return false;
  }
  return true;
}

string conv(int n, int b) {
  string res;
  int r;

  while (n) {
    r = n % b;
    res += d[r];
    n /= b;
  }

  return res;
}

int main(void)
{
#ifdef _DEBUG
  freopen("h.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  for (int i = 0; i < 10; ++i) d[i] = '0' + i;
  for (int i = 10; i < 36; ++i) d[i] = 'A' + (i - 10);

  int n, s;
  while (~scanf("%d%d", &n, &s)) {
    bool flag = false;

    for (int i = 2; i <= n; ++i) {
      string r = conv(s, i);
      if (check(r)) {
        flag = true;
        printf("%d %s\n", i, r.c_str());
      }
    }

    if (!flag) printf("guomienasai\n");
  }

  return 0;
}
