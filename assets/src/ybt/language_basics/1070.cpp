#include <iostream>
using namespace std;
int main() {
  double x, r = 1; int n; cin >> x >> n; cout.precision(4);
  r = x;
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < n; i++) {
    r *= (1 + 0.001);
  }
  cout << r << endl;
  return 0;
}
