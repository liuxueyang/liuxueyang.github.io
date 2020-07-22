#include <iostream>
using namespace std;
int main() {
  double r; cin >> r;
  double pi = 3.14;
  cout.precision(2); cout.setf(ios::fixed, ios::floatfield);
  cout << 4./3. * pi * r*r*r << endl;
  return 0;
}
