// Date: Mon Oct 18 10:46:52 2021

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

class Solution {
public:
  bool areNumbersAscending(string s) {
    int cnt = 0, pre = -1, n = s.size(), cur = 0;
    for (int i = 0; i < n; ++i) {
      if (isdigit(s[i])) {
        while (i < n && isdigit(s[i])) {
          cur = cur * 10 + (s[i] - '0');
          ++i;
        }
        --i;

        cnt++;

        if (cur <= pre) {
          return false;
        } else {
          pre = cur;
        }
      } else {
        cur = 0;
      }
    }

    if (cnt < 2) return false;
    return true;
  }
};
