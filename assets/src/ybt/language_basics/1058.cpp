#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double a, b, c; cin >> a >> b >> c; cout.precision(5);
  cout.setf(ios::fixed, ios::floatfield);
  double delta = b*b - 4*a*c, eps = 1e-9, res, res1, res2;
  if (delta < 0) {
    cout << "No answer!\n";
  } else if (fabs(delta) < eps) {
    res = -b / (2*a);
    cout << "x1=x2=" << res << endl;
  } else {
    double t = sqrt(delta);
    res1 = (-b + t) / (2*a);
    res2 = (-b - t) / (2*a);
    if (res1 > res2) {
      double k = res1;
      res1 = res2;
      res2 = k;
    }
    cout << "x1=" << res1 << ";x2=" << res2 << endl;
  }
  return 0;
}
