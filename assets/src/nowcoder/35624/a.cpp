// Date: Sun May 29 13:12:08 2022

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

const int N = 10010;
char stk[N], s1[N], s2[N];
int tt, n, m;

int main(void)
{
#ifdef _DEBUG
  freopen("a.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (~scanf("%d%d", &n, &m)) {
    scanf("%s%s", s1, s2);
    bool flag = true;
    tt = 0;
    int i, j, len2 = strlen(s2);

    for (i = 0, j = 0; i < len2; ++i) {
      if (tt && stk[tt] == s2[i]) {
        --tt;
        continue;
      }

      if (j < n) {
        if (s2[i] == s1[j]) {
          ++j;
          continue;
        }

        while (j < n && tt < m && s2[i] != s1[j]) {
          stk[++tt] = s1[j++];
        }

        if (j < n && s2[i] == s1[j]) {
          ++j;
        } else {
          flag = false; break;
        }
      } else {
        flag = false; break;
      }
    }

    if (j != n || tt) flag = false;

    if (flag) {printf("Don't you think that's Funny?\n");}
    else printf("That's not Funny at all!\n");
  }

  return 0;
}
