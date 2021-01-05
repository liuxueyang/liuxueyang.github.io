#include <iostream>
#include <cstring>

using namespace std;

const int N = 123;
int a[N][N], d[N][N], n, tmp, res;

int main() {
#ifdef DEBUG
  freopen("1288.in", "r", stdin);
#endif

  cin >> n;
  memset(a, 0, sizeof a);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      cin >> a[i][j];
    }
  }
  memset(d, 0, sizeof d);
  d[0][0] = a[0][0];
  res = -0x3f3f3f3f;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      d[i][j] = d[i - 1][j] + a[i][j];
      if (j > 0) {
        tmp = d[i - 1][j - 1] + a[i][j];
        if (tmp > d[i][j]) d[i][j] = tmp;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (res < d[n-1][i]) res = d[n-1][i];
  }
  cout << res << endl;

  return 0;
}
