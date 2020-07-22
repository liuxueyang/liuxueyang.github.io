#include <iostream>
using namespace std;
int main() {
  double f; cin >> f; cout.precision(5);
  cout.setf(ios::fixed, ios::floatfield);
  cout << 5. * (f-32) / 9. << endl;
  return 0;
}
