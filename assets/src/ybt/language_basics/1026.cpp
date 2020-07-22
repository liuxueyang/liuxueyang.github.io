#include <iostream>
using namespace std;
int main() {
  char a; int b; float c; double d;
  cin >> a >> b >> c >> d;
  cout.precision(6); cout.setf(ios::fixed, ios::floatfield);
  cout << a << " " << b << " " << c << " " << d << endl;
  return 0;
}
