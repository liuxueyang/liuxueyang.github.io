#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  cout.precision(3); cout.setf(ios::fixed, ios::floatfield);
  double res = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  cout << res << endl;
  return 0;
}
