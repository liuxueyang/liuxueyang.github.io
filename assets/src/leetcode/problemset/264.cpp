// Date: Sat Oct  9 15:34:15 2021

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

const int N = 1700;
int d[N];

class Solution {
public:
  int nthUglyNumber(int n) {
    d[0] = 1;
    int p2 {}, p3 {}, p5{};
    for (int i = 1; i < n; ++i) {
      d[i] = min(d[p2] * 2,
                 min(d[p3] * 3, d[p5] * 5));
      if (d[i] == d[p2] * 2) ++p2;
      if (d[i] == d[p3] * 3) ++p3;
      if (d[i] == d[p5] * 5) ++p5;
    }
    return d[n - 1];
  }
};
