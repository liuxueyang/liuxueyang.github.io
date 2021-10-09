// Date: Sat Oct  9 17:48:03 2021

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
  int maxScoreSightseeingPair(vector<int>& a) {
    int n = a.size();
    VI d(n, 0);
    d[0] = a[0] + 0;
    for (int i = 1; i < n; ++i) d[i] = max(d[i - 1], a[i] + i);
    int res = a[1] - 1 + d[0];
    for (int i = 1; i < n; ++i) res = max(res, a[i] - i + d[i - 1]);
    return res;
  }
};
