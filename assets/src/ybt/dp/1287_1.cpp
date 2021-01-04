#include <iostream>
#include <cstring>

using namespace std;

const int N = 123, MAX = 0x3f3f3f3f;
int a[N][N], n, d[N][N], tmp, res;

int main() {
  #ifdef DEBUG
  freopen("1287.in", "r", stdin);
  #endif

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      d[i][j] = MAX;
    }
  }
  d[0][0] = a[0][0];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i+j == 0) continue;
      if (i > 0) {
        tmp = d[i-1][j] + a[i][j];
        if (tmp < d[i][j]) d[i][j] = tmp;
      }
      if (j > 0) {
        tmp = d[i][j-1] + a[i][j];
        if (tmp < d[i][j]) d[i][j] = tmp;
      }
    }
  }
  cout << d[n-1][n-1] << endl;

  return 0;
}
