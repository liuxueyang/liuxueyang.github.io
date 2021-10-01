// Date: Thu Sep 30 18:23:31 2021

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
  bool canJump(vector<int>& a) {
    int n = a.size();
    int cur = 0;

    for (int i = 0; i <= cur; ++i) {
      cur = max(cur, i + a[i]);
      if (cur >= n - 1) return true;
    }

    return false;
  }
};
