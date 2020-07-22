#include <iostream>
#include <cmath>
using namespace std;
int main() {
  double x, y; char c; cin >> x >> c;
  if (x <= 1000) y = 8;
  else {
    y = 8 + ceil((x - 1000) / 500) * 4;
  }
  if (c == 'y') y += 5;
  cout << int(y) << endl;

  return 0;
}
