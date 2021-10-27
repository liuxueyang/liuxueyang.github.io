// Date: Wed Oct 27 16:24:49 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

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
typedef vector<int> VI;
typedef pair<int, int> PII;

#ifdef _DEBUG

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

typedef ListNode LN;
typedef LN* LNP;

#endif

const int N = 10010;
int d[N], a[110];

class Solution {
public:
  int numSquares(int n) {
    for (int i = 1; i <= 100; ++i) a[i] = i * i;
    memset(d, 0x3f, sizeof d);
    d[0] = 0;

    for (int i = 1; i <= 100; ++i) {
      for (int j = a[i]; j <= n; ++j) {
        d[j] = min(d[j], d[j - a[i]] + 1);
      }
    }

    return d[n];
  }
};
