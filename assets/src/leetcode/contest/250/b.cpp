// Date: Sun Jul 18 10:28:42 2021

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
    int addRungs(vector<int>& a, int b) {
      int res = 0, cur = 0;
      for (auto &c : a) {
	int t = c - cur;
	if (t % b == 0) {
	  res += t / b - 1;
	} else {
	  res += t / b;
	}

	cur = c;
      }
      
      return res;
    }
};
