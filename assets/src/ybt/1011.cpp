#include <iostream>
using namespace std;
int main() {
  int a, b; cin >> a >> b; cout.precision(3);
  cout.setf(ios::fixed, ios::floatfield);
  cout << b * 1. / a * 100. << "%" << endl;
  return 0;
}
