#include <iostream>
using namespace std;
int main() {
  int a, b; cin >> a >> b; cout.precision(9);
  cout.setf(ios::fixed, ios::floatfield);
  cout << a * 1. / b << endl;
  return 0;
}
