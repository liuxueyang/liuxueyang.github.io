#include <iostream>
using namespace std;
int main() {
  double a; cin >> a; cout.precision(12);
  cout.setf(ios::fixed, ios::floatfield);
  cout << a << endl;
  return 0;
}
