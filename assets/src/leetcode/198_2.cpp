// Date: Wed Oct 27 17:19:38 2021

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

#ifdef _DEBUG

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

typedef ListNode LN;
typedef LN* LNP;

#endif

const int N = 110;
int d[N];

class Solution {
public:
  int rob(vector<int>& a) {
    memset(d, 0, sizeof d);
    int n = a.size();

    if (n == 1) return a[0];

    d[0] = a[0];
    d[1] = max(a[0], a[1]);

    for (int i = 2; i < n; ++i) {
      d[i] = max(d[i - 2] + a[i], d[i - 1]);
    }

    return d[n - 1];
  }
};
