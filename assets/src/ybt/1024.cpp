#include <iostream>
using namespace std;
int main() {
  float a; cin >> a; cout.precision(3);
  cout.setf(ios::fixed, ios::floatfield); cout << a << endl;
  return 0;
}
