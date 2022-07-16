// Date: Sat Oct  9 17:00:43 2021

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
  int numberOfArithmeticSlices(vector<int>& a) {
    int n = a.size();
    VI d(n, 0);
    int res {};

    for (int i = 2; i < n; ++i) {
      if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
        d[i] = d[i - 1] + 1;
        res += d[i];
      }
    }
    return res;
  }
};
