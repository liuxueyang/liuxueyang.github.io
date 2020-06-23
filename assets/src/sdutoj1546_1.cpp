#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 100;
int a[N][N], b[N];
bool d[N][N], res[N];

int main() {

  #ifdef DEBUG
  freopen("sdutoj1546.in", "r", stdin);
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

    for (int i = 1; i <= 2*n; i++) {
      for (int j = i; j <= 2*n; j++)
        d[i][j] = d[j][i] = (i+1==j ? true : false);
    }

    for (int len = 2; len <= n; len++) {
      for (int i = 1; i + len <= 2*n; i++) {
        int j = i + len;
        for (int m = i + 1; m < j; m++) {
          int i1 = (i % n == 0 ? n : i % n);
          int m1 = (m % n == 0 ? n : m % n);
          int j1 = (j % n == 0 ? n : j % n);

          if ( (d[m][j] && d[i][m]) &&
               (a[i1][m1] || a[j1][m1])) {
            d[i][j] = d[j][i] = true;
            break;
          }
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      cout << (d[i][i+n] ? 1 : 0) << endl;
    }

    if (tt != T - 1) cout << endl;
  }

  return 0;
}
