#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long LL;
LL a[8][8], d[15][8][8][8][8], s[8][8][8][8];
int n;
const LL MAX = 0x7fffffff;

int D(int x)
{
  return x*x;
}

int fun(int k, int x1, int y1, int x2, int y2)
{
  if (d[k][x1][y1][x2][y2] != MAX)
    {
      return d[k][x1][y1][x2][y2];
    }
  if (k == 0)
    {
      LL res = D(s[x1][y1][x2][y2]);
      d[k][x1][y1][x2][y2] = res;
      return res;
    }

  LL res = d[k][x1][y1][x2][y2];

  for (int a = 0; a < 7; a++)
    {
      LL tmp1 = D(s[x1][y1][a][y2]) + fun(k - 1, a + 1, y1, x2, y2);
      LL tmp2 = fun(k - 1, x1, y1, a, y2) + D(s[a+1][y1][x2][y2]);
      res = min(min(tmp1, tmp2), res);
    }

  for (int a = 0; a < 7; a++)
    {
      LL tmp1 = D(s[x1][y1][x2][a]) + fun(k - 1, x1, a + 1, x2, y2);
      LL tmp2 = fun(k - 1, x1, y1, x2, a) + D(s[x1][a+1][x2][y2]);
      res = min(res, min(tmp1, tmp2));
    }

  d[k][x1][y1][x2][y2] = res;
  return res;
}

int main(void)
{

  #ifdef DEBUG
  freopen("poj1191.in", "r", stdin);
  #endif

  while (cin >> n)
    {
      for(int i = 0; i < 15; i++)
        {
          for (int x1 = 0; x1 < 8; x1++)
            for (int y1 = 0; y1 < 8; y1++)
              for (int x2 = 0; x2 < 8; x2++)
                for (int y2 = 0; y2 < 8; y2++)
                  d[i][x1][y1][x2][y2] = MAX;
        }
      double sum = 0;

      for (int i = 0; i < 8; i++)
        {
          for (int j = 0; j < 8; j++)
            {
              cin >> a[i][j];
              sum += a[i][j];
            }
        }

      sum /= n;

      for (int x1 = 0; x1 < 8; x1++)
        {
          for (int y1 = 0; y1 < 8; y1++)
            {
              for (int x2 = x1; x2 < 8; x2++)
                {
                  for (int y2 = y1; y2 < 8; y2++)
                    {
                      s[x1][y1][x2][y2] = 0;
                      for (int i = x1; i <= x2; i++)
                        {
                          for (int j = y1; j <= y2; j++)
                            {
                              s[x1][y1][x2][y2] += a[i][j];
                            }
                        }
                    }
                }
            }
        }

      double res = fun(n - 1, 0, 0, 7, 7);
      res = sqrt(res / n - sum * sum);
      printf("%.3f\n", res);
    }

  return 0;
}
