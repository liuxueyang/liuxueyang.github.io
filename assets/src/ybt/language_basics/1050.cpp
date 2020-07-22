#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double x; cin >> x;
  double b = x / 3 + 50;
  double w = x / 1.2;
  double eps = 1e-9;
  if (fabs(b-w) < eps) {
    cout << "All\n";
  } else if (b < w) cout << "Bike\n";
  else cout << "Walk\n";
  return 0;
}
