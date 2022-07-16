// Date: Wed Oct 27 10:45:19 2021

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

const int N = 10010;
bool d[N];

class Solution {
public:
  bool canPartition(vector<int>& a) {
    memset(d, false, sizeof d);
    d[0] = true;
    int sum = 0;
    for (auto &x : a) sum += x;
    if (sum & 1) return false;

    int n = a.size();
    sum >>= 1;
    for (int i = 0; i < n; ++i) {
      for (int v = sum; v >= a[i]; --v) {
        d[v] = d[v] || d[v - a[i]];
      }
    }

    return d[sum];
  }
};
