// Date: Sun Jul 18 10:48:41 2021

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
    long long maxPoints(vector<vector<int>>& a) {
      int n = a.size(), m = a[0].size();
      vector<vector<ll>> b(n, vector<ll>(m, 0));

      for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
	  b[i][j] = a[i][j];
      
      for (int i = 1; i < n; ++i) {
	for (int j  = 0; j < m; ++j) {
	  ll t = b[i - 1][j];
	  for (int k = 0; k < m; ++k) {
	    ll t1 = b[i - 1][k] - abs(k - j);
	    if (t1 > t) t = t1;
	  }

	  b[i][j] += t;
	}
      }

      ll res = -1;
      for (int j = 0; j < m; ++j) {
	res = max(b[n - 1][j], res);
      }

      return res;
    }
};
