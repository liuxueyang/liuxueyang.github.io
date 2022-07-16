// Date: Thu Oct 14 14:30:01 2021

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

const int N = 50, M = 3010;
int d[N][M];

class Solution {
public:
  int lastStoneWeightII(vector<int>& a) {
    int n = a.size(), sum = 0;
    memset(d, 0, sizeof d);

    for (int i = 0; i < n; ++i) sum += a[i];
    int ha = sum / 2, res = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= ha; ++j) {
        if (i == 0) {
          if (j >= a[i]) d[i][j] = a[i];
        } else {
          if (j >= a[i]) {
            d[i][j] = max(d[i][j], d[i - 1][j - a[i]] + a[i]);
          }
          d[i][j] = max(d[i][j], d[i - 1][j]);
        }

        res = max(res, d[i][j]);
      }
    }

    int res1 = sum - res;

    return abs(res1 - res);
  }
};
