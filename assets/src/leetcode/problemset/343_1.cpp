// Date: Wed Oct 13 20:32:00 2021

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

const int N = 100;
int d[N];

class Solution {
public:
  int integerBreak(int n) {
    memset(d, 0, sizeof d);
    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        d[i] = max(d[i], max(d[j], j) * (i - j));
      }
    }

    return d[n];
  }
};
