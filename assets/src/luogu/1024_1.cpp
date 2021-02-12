#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const double eps = 1e-4;
double a, b, c, d;

double fun(double x) {
  return a* x*x*x + b* x*x + c*x + d;
}

double bsearch(double l, double r) {
  if (fun(l) == 0) return l;
  double mid, gr, gm;
  while (r - l >= 1e-3) {
    mid = (l + r) / 2;
    gr = fun(r);
    gm = fun(mid);
    if (gr * gm <= 0) l = mid;
    else r = mid;
  }
  return r;
}

int main(int argc, char *argv[])
{
  #ifdef _DEBUG
  freopen("1024.in", "r" ,stdin);
  #endif

  cin >> a >> b >> c >> d;
  int cnt = 0;

  for (int i = -100; i <= 100; ++i) {
    double l = i, r = i + 1;
    double gl = fun(l), gr = fun(r);

    if (gl == 0) {
      printf("%.2lf ", l);
      ++cnt;
    }
    else if (gl * gr < 0) {
      printf("%.2lf ", bsearch(l, r));
      ++cnt;
    }
    if (cnt == 3) break;
  }
  puts("");
  return 0;
}
