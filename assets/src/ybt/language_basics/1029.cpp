#include <iostream>
using namespace std;
int main() {
  double a, b; cin >> a >> b;
  int d = int(a / b);
  double c = a - d * b;
  cout << c << endl;
  return 0;
}
