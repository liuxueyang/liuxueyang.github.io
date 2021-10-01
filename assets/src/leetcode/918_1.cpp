// Date: Fri Oct  1 14:49:41 2021

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
  int maxSubarraySumCircular(vector<int>& a) {
    int n = a.size(), cur = a[0], r1 = a[0];
    for (int i = 1; i < n; ++i) {
      if (cur < 0) cur = a[i];
      else cur += a[i];
      r1 = max(r1, cur);
    }

    int r2 = a[0];
    cur = a[0];
    for (int i = 1; i < n; ++i) {
      if (cur > 0) cur = a[i];
      else cur += a[i];
      r2 = min(r2, cur);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];

    if (r2 != sum) r2 = sum - r2;
    else r2 = r1;

    int res = max(r1, r2);

    return res;
  }
};
