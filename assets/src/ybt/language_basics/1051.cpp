#include <iostream>
using namespace std;
int main() {
  double n; cin >> n;
  double y; cout.precision(3);
  cout.setf(ios::fixed, ios::floatfield);
  if (n >= 0 && n < 5) y = -n + 2.5;
  else if (n >= 5 && n < 10) y = 2-1.5*(n-3)*(n-3);
  else y = n/2. - 1.5;
  cout << y << endl;
  return 0;
}
