#include <iostream>
using namespace std;
int main() {
  double x, a, b, c, d; cout.precision(7);
  cout.setf(ios::fixed, ios::floatfield);
  cin >> x >> a >> b >> c >> d;
  cout << a*x*x*x + b*x*x + c*x + d << endl;
  return 0;
}
