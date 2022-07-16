// Date: Thu Sep 30 11:40:50 2021

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


class Solution {
public:
  int rob(vector<int>& a) {
    int n = a.size();
    int res = 0;

    VI d(n, 0);
    d[0] = a[0];

    if (n == 1) return a[0];
    d[1] = max(a[1], d[0]);

    for (int i = 2; i < n; ++i) {
      d[i] = max(d[i - 2] + a[i], d[i - 1]);
    }

    for (int i = 0; i < n; ++i) res = max(res, d[i]);

    return res;
  }
};
