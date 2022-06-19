// Date: Mon May 30 00:47:41 2022

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

const int N = 510;
int n;
char a[N];
int d[N][N];

int main(void)
{
#ifdef _DEBUG
  freopen("200.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d", &n)) {
    scanf("%s", a + 1);
    memset(d, 0, sizeof d);

    for (int k = 2; k <= n; ++k) {
      for (int i = 1; i + k - 1 <= n; ++i) {
        int j = i + k - 1;
        for (int s = i + 1; s + 1 < j; ++s) {
          d[i][j] = max(d[i][j], d[i][s] + d[s + 1][j]);
        }

        if (a[i] == '(' && a[j] == ')') d[i][j] = max(d[i][j], 2 + d[i + 1][j - 1]);
        else if (a[i] == '[' && a[j] == ']') d[i][j] = max(d[i][j], 2 + d[i + 1][j - 1]);
        else d[i][j] = max(d[i][j], max(d[i + 1][j], d[i][j - 1]));
      }
    }

    printf("%d\n", d[1][n]);
  }

  return 0;
}
