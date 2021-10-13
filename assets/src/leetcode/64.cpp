// Date: Wed Oct 13 11:10:52 2021

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

const int N = 210;
int d[N][N];

class Solution {
public:
  int minPathSum(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    memset(d, 0x3f, sizeof d);
    d[0][0] = a[0][0];

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x = INF, y = INF;
        if (i) x = d[i - 1][j];
        if (j) y = d[i][j - 1];
        if (i || j) d[i][j] = min(x, y) + a[i][j];
        else d[i][j] = a[i][j];
      }
    }

    return d[n - 1][m - 1];
  }
};
