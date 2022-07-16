// Date: Fri Oct  1 14:25:30 2021

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
  int maxSubArray(vector<int>& a) {
    int n = a.size(), res = a[0], cur = a[0];
    for (int i = 1; i < n; ++i) {
      if (cur < 0) {
        cur = a[i];
      } else {
        cur += a[i];
      }

      res = max(res, cur);
    }

    return res;
  }
};
