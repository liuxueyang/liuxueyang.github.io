// Date: Sun Feb 20 20:03:50 2022

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

const int N = 110, M = 10010;
bool d[N][M];

int main(void)
{
#ifdef _DEBUG
  freopen("c.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, X;
  while (cin >> n >> X) {
    vector<PII> num;
    num.push_back(PII(0, 0));

    for (int i = 0; i < n; ++i) {
      int a, b; cin >> a >> b;
      num.push_back(PII(a, b));
    }

    memset(d, false, sizeof d);

    d[0][0] = true;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= X; ++j) {
        if (j >= num[i].first) d[i][j] = d[i][j] || d[i - 1][j - num[i].first];
        if (j >= num[i].second) d[i][j] = d[i][j] || d[i - 1][j - num[i].second];
      }
    }

    // int cur = 0;
    // queue<PII> q;
    // q.push({0, 0});
    // bool flag = false;

    // while (!q.empty()) {
    //   auto t = q.front(); q.pop();
    //   auto step = t.second;
    //   cur = t.first;

    //   if (cur == X && step == n) {
    //     flag = true; break;
    //   }

    //   int step1 = step + 1;
    //   int ne = cur;

    //   if (step1 <= n) {
    //     ne = cur + num[step1].first;
    //     if (ne <= X) {
    //       q.push(PII(ne, step1));
    //     }
    //     if (ne == X && step1 == n) {
    //       flag = true; break;
    //     }

    //     ne = cur + num[step1].second;
    //     if (ne <= X) {
    //       q.push(PII(ne, step1));
    //     }
    //     if (ne == X && step1 == n) {
    //       flag = true; break;
    //     }
    //   }
    // }

    cout << (d[n][X] ? "Yes\n" : "No\n");
  }

  return 0;
}
