// Date: Thu Sep 30 12:04:34 2021

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

const int N = 10010, M = 10000;
int d[N], cnt[N];

class Solution {
public:
  int deleteAndEarn(vector<int>& a) {
    int n = a.size();
    int res = 0;

    memset(d, 0, sizeof d);
    memset(cnt, 0, sizeof cnt);

    for (int i = 0; i < n; ++i) cnt[a[i]]++;

    d[1] = cnt[1];
    for (int i = 2; i <= M; ++i) d[i] = max(d[i - 1], d[i - 2] + i * cnt[i]);
    res = d[M];

    return res;
  }
};
