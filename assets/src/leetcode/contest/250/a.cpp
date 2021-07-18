// Date: Sun Jul 18 10:28:38 2021

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
    int canBeTypedWords(string s, string a) {
      stringstream ss(s);
      string t;
      int st[26] {0};
      
      for (auto &c : a) st[c - 'a'] = 1;

      int res = 0;
      while (ss >> t) {
	bool flag = false;
	for (auto &c : t) {
	  if (st[c - 'a']) {
	    flag = true;
	    break;
	  }
	}
	if (!flag) res++;
      }
      return res;
    }
};
