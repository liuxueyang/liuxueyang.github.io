// Date: Sat Feb 19 20:21:11 2022

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
int primes[N], cnt;
bool st[N];

void get_primes(int n) {
  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) {
      primes[cnt++] = i;
      for (ll j = ll(i) * i; j <= n; j += i) {
        st[j] = true;
      }
    }
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  get_primes(1000);
  // printf("cnt=%d\n", cnt);
  // for (int i = 0; i < cnt; ++i) printf("%d ", primes[i]);
  // printf("\n");

  int A, B, C, D;
  while (cin >> A >> B >> C >> D) {
    bool win = false;

    for (int i = A; i <= B; ++i) {
      bool flag = false;

      for (int j = C; j <= D; ++j) {
        if (!st[i + j]) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        win = true;
        break;
      }
    }

    cout << (!win ? "Aoki" : "Takahashi") << "\n";
  }

  return 0;
}
