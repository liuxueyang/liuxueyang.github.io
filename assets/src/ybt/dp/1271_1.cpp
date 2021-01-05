#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 30, N = 100, K = 1111, MAX = 0x3f3f3f3f;
int a[K], b[K], c[K], m, n, k, d[M][N];

int main() {
#ifdef DEBUG
  freopen("1271.in", "r", stdin);
#endif

  cin >> m >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  memset(d, MAX, sizeof d);
  d[0][0] = 0;
  for (int i = 0; i < k; ++i) {
    for (int m1 = m; m1 >= 0; --m1) {
      for (int n1 = n; n1 >= 0; --n1) {
        int m2 = min(m1 + a[i], m);
        int n2 = min(n1 + b[i], n);

        if (d[m2][n2] > d[m1][n1] + c[i]) {
          d[m2][n2] = d[m1][n1] + c[i];
        }
      }
    }
  }
  cout << d[m][n] << endl;

  return 0;
}
