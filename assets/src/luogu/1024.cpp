#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-4;
double a, b, c, d;

double fun(double x) {
  return a* x*x*x + b* x*x + c*x + d;
}

double bsearch(double l, double r) {
  if (fun(l) == 0) return l;
  double mid, gl, gm;
  while (r - l > eps) {
    mid = (l + r) / 2;
    gl = fun(l);
    gm = fun(mid);
    if (gl * gm <= 0) r = mid;
    else l = mid;
  }
  return l;
}

int main(int argc, char *argv[])
{
  #ifdef _DEBUG
  freopen("1024.in", "r" ,stdin);
  #endif

  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  int cnt = 0;

  for (int i = -100; i <= 100; ++i) {
    double l = i, r = i + 1;
    if (fun(l) == 0) {
      ++cnt;
      printf("%.2lf ", l);
    } else if (fun(l) * fun(r) < 0) {
      printf("%.2lf ", bsearch(l, r));
      ++cnt;
    }
    if (cnt == 3) break;
  }
  puts("");
  return 0;
}
