#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int n, x, y; cin >> n >> x >> y;
  int re = n - ceil(y * 1.0 / x);
  cout << (re >= 0 ? re : 0) << endl;
  return 0;
}
