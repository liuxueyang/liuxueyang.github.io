// Date: Wed Oct 13 15:31:31 2021

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
const int N = 1010;
int d[N][N];

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    memset(d, 0, sizeof d);
    int res = 1;

    for (int i = 0; i < n; ++i) d[i][i] = 1;
    for (int k = 1; k < n; ++k) {
      for (int i = 0; i + k < n; ++i) {
        int j = i + k;
        if (s[i] == s[j]) {
          d[i][j] = max(d[i + 1][j - 1] + 2,
                        max(d[i][j - 1], d[i + 1][j]));
        } else {
          d[i][j] = max(d[i][j - 1], d[i + 1][j]);
        }

        res = max(res, d[i][j]);
      }
    }

    return res;
  }
};
