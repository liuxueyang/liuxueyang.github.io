#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double h, r, v; cin >> h >> r; v = 3.1415926 * r*r * h;
  int re = ceil(20 * 1000 / v);
  cout << re << endl;
  return 0;
}
