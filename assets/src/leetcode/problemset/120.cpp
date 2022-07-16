// Date: Sat Oct  9 14:06:30 2021

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

const int N = 300;
int d[N][N];

class Solution {
public:
  int minimumTotal(vector<vector<int>>& a) {
    int n = a.size();
    int res = INF;
    memset(d, 0x3f, sizeof d);
    d[0][0] = a[0][0];

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        int tmp = INF;

        if (j == 0) tmp = d[i - 1][j];
        else if (j == i) tmp = d[i - 1][j - 1];
        else tmp = min(d[i - 1][j - 1], d[i - 1][j]);

        d[i][j] = tmp + a[i][j];
      }
    }

    for (int j = 0; j < n; ++j) res = min(res, d[n - 1][j]);
    return res;
  }
};
