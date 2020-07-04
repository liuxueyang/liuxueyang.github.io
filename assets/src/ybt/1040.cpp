#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double a; cin >> a;
  cout.precision(2); cout.setf(ios::fixed, ios::floatfield);
  cout << fabs(a) << endl;
  return 0;
}
