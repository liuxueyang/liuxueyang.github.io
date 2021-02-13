#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const int N = 100010;
const double eps = 1e-6, INF = 1e10 + 100;
int a[N], b[N], p, n;

double bsearch(double l, double r) {
  double mid;
  while (r - l > eps) {
    mid = (l + r) / 2;

    double sum = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] >= a[i] * mid) continue;
      sum += a[i] * mid - b[i];
    }

    if (sum <= mid * p) l = mid;
    else r = mid;
  }

  return l;
}

int main() {
  #ifdef _DEBUG
  freopen("3743.in", "r", stdin);
  #endif

  scanf("%d%d", &n, &p);
  double sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", a + i, b + i);
    sum += a[i];
  }
  if (p >= sum) {
    printf("-1\n");
  } else 
    printf("%.6lf\n", bsearch(0, INF));

  return 0;
}
