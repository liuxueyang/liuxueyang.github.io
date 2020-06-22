#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 100;
int a[N][N], b[N];
bool d[N][N], res[N];

int main() {

  #ifdef DEBUG
  freopen("sdoj1546.in", "r", stdin);
  #endif
  int T;
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      res[i] = false;
      for (int j = 1; j <= n; j++) {
        cin >> a[i][j];
      }
    }

    for (int _i = 0; _i < n; _i++) {
      int b1[N];
      for (int i = 1; i <= n; i++) b[i] = b1[i] = i;
      for (int i = _i + 1, j = 1; i <= n; i++, j++) b[j] = b[i];
      for (int i = 1, j = n - _i + 1; j <= n; i++, j++) b[j] = b1[i];
      b[n+1] = b[1];
      for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= n + 1; j++)
          d[i][j] = false;

      for (int len = 1; len <= n; len++) {
        for (int i = n; i >= 1; i--) {
          int j = i + len;
          if (j > n + 1) continue;
          if (len == 1) {
            d[i][j] = d[j][i] = true;
            continue;
          }
          for (int m = i + 1; m < j; m++) {
            if ( (d[j][m] && d[i][m]) &&
                 (a[b[j]][b[m]] || a[b[i]][b[m]])) {
              d[i][j] = d[j][i] = true;
              break;
            }
          }
        }
      }

      if (d[1][n+1]) res[b[1]] = true;
    }

    for (int i = 1; i <= n; i++) {
      cout << (res[i] ? 1 : 0) << endl;
    }

    if (tt != T - 1) cout << endl;
  }

  return 0;
}
