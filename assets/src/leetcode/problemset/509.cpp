// Date: Mon Sep 27 14:59:35 2021

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
  int fib(int n) {
    ll a = 0, b = 1, c = a + b;
    if (n == 0) return a;
    else if (n == 1) return b;
    n--;
    while (n--) {
      c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
};
