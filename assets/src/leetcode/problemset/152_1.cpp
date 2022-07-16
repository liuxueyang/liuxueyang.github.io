// Date: Sat Oct  2 08:09:56 2021

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
  int maxProduct(vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;

    VI d1(n, 0), d2(n, 0);
    d1[0] = d2[0] = a[0];

    int res = d1[0];

    for (int i = 1; i < n; ++i) {
      d1[i] = max(a[i], max(d1[i - 1] * a[i],
                            d2[i - 1] * a[i]));
      res = max(res, d1[i]);
      d2[i] = min(a[i], min(d1[i - 1] * a[i],
                            d2[i - 1] * a[i]));
    }

    return res;
  }
};
