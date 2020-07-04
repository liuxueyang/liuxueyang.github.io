#include <iostream>
using namespace std;
int main() {
  double pi = 3.14159, r; cin >> r; cout.precision(4);
  cout.setf(ios::fixed, ios::floatfield);
  cout << 2*r << " "
       << 2*pi*r << " "
       << pi*r*r << endl;
  return 0;
}
