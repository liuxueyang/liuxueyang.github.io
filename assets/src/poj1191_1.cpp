#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long LL;
const int X = 10;
LL a[X][X], d[15][X][X][X][X], r[X][X];
int vis[15][X][X][X][X];
int n;
const LL oo = 0x7fffffff;

template<typename T>
T D(T x) {return x * x;}

LL area(int x1, int y1, int x2, int y2) {
  return r[x2][y2] + r[x1-1][y1-1] - r[x1-1][y2] - r[x2][y1-1];
}

LL fun2(int K) {
  for (int k = 0; k <= K; k++) {
    for (int x1 = 8; x1 >= 1; x1--) {
      for (int y1 = 8; y1 >= 1; y1--) {
        for (int x2 = x1; x2 <= 8; x2++) {
          for (int y2 = y1; y2 <= 8; y2++) {
            LL &res = d[k][x1][y1][x2][y2];
            res = oo;
            if (k == 0) {
              res = D<LL>(area(x1, y1, x2, y2));
              continue;
            }
            
            for (int a = x1; a < x2; a++) {
              LL tmp1 = d[0][x1][y1][a][y2] + d[k-1][a+1][y1][x2][y2];
              LL tmp2 = d[k-1][x1][y1][a][y2] + d[0][a+1][y1][x2][y2];
              res = min(res, min(tmp1, tmp2));
            }
            for (int a = y1; a < y2; a++) {
              LL tmp1 = d[0][x1][y1][x2][a] + d[k-1][x1][a+1][x2][y2];
              LL tmp2 = d[k-1][x1][y1][x2][a] + d[0][x1][a+1][x2][y2];
              res = min(res, min(tmp1, tmp2));
              // cout << "tmp1=" << tmp1
              //      << " tmp2=" << tmp2 << endl;
            }
            // cout << "x1="<< x1 << " y1=" << y1 << " x2=" << x2 << " y2=" << y2 <<
            //   " res=" << res
            //      << " k=" << k << endl;
          }
        }
      }
    }
  }
  // cout << d[K][1][1][8][8] << endl;
  return d[K][1][1][8][8];
}

int main(void)
{

  #ifdef DEBUG
  freopen("poj1191.in", "r", stdin);
  #endif

  cin >> n;
  double sum = 0;

  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++) {
      cin >> a[i][j];
      sum += a[i][j];
    }
  sum /= n;
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      r[i][j] = a[i][j] + r[i-1][j] + r[i][j-1] - r[i-1][j-1];

  double res = fun2(n - 1);
  // cout << "res=" << res << " sum=" << sum << endl;
  res = sqrt(res / n - sum * sum);
  printf("%.3lf\n", res);

  return 0;
}
