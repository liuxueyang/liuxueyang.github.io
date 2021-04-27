#include <iostream>

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("ccisland.in", "r", stdin);
  #endif

  double x, y, xr, yr, d;
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> xr >> yr >> d;
    double d1 = min(x / xr, y / yr);
    if (d1 >= d) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
