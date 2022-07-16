// Date: Mon Sep 27 21:11:50 2021

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
    int n = a.size();
    int cur = a[0], res = a[0];
    for (int i = 1; i < n; ++i) {
      if (cur <= 0) {
        cur = a[i];
      } else {
        cur = max(a[i], a[i] + cur);
      }
      res = max(res, cur);
    }
    return res;
  }
};
