// Date: Wed Oct 27 10:53:33 2021

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

const int N = 2010;
int d[N];

class Solution {
public:
  int lastStoneWeightII(vector<int>& a) {
    int n = a.size(), sum {};
    for (auto &x : a) sum += x;
    int tot = sum;

    sum >>= 1;
    memset(d, 0, sizeof d);

    for (int i = 0; i < n; ++i) {
      for (int v = sum; v >= a[i]; --v) {
        d[v] = max(d[v], d[v - a[i]] + a[i]);
      }
    }

    if (d[sum] * 2 == tot) return 0;
    return abs(tot - 2 * d[sum]);
  }
};
