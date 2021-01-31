#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;
int d[N][N];

class Solution {
public:
  bool checkPartitioning(string s) {
    memset(d, 0, sizeof d);
    int n = s.size();

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        if (i == j) d[i][j] = 1;
        else if (j - i == 1) d[i][j] = (s[i] == s[j]);
        else d[i][j] = ((s[i] == s[j]) && d[i+1][j-1]);
      }
    }

    for (int k = 1; k <= n - 2; ++k) {
      for (int j = k; j <= n - 2; ++j) {
        if (d[0][k-1] && d[k][j] && d[j+1][n-1]) return true;
      }
    }

    return false;
  }
};
