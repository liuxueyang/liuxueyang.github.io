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
const LL MAX = 0x7fffffff;

template<typename T>
T D(T x) {return x * x;}

LL area(int x1, int y1, int x2, int y2) {
  return r[x2][y2] + r[x1-1][y1-1] - r[x1-1][y2] - r[x2][y1-1];
}

int fun(int k, int x1, int y1, int x2, int y2)
{
  if (vis[k][x1][y1][x2][y2])
      return d[k][x1][y1][x2][y2];

  if (k == 0)
    {
      LL res = D<LL>(area(x1, y1, x2, y2));
      d[k][x1][y1][x2][y2] = res;
      vis[k][x1][y1][x2][y2] = 1;
      return res;
    }

  LL &res = d[k][x1][y1][x2][y2];
  res = MAX;

  for (int a = 1; a <= 7; a++)
    {
      LL tmp1 = fun(0, x1, y1, a, y2) + fun(k - 1, a + 1, y1, x2, y2);
      LL tmp2 = fun(k - 1, x1, y1, a, y2) + fun(0, a+1, y1, x2, y2);
      res = min(min(tmp1, tmp2), res);
    }

  for (int a = 1; a <= 7; a++)
    {
      LL tmp1 = fun(0, x1, y1, x2, a) + fun(k - 1, x1, a + 1, x2, y2);
      LL tmp2 = fun(k - 1, x1, y1, x2, a) + fun(0, x1, a+1, x2, y2);
      res = min(res, min(tmp1, tmp2));
    }
  vis[k][x1][y1][x2][y2] = 1;
  return res;
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

  double res = fun(n - 1, 1, 1, 8, 8);
  res = sqrt(res / n - sum * sum);
  printf("%.3lf\n", res);

  return 0;
}
