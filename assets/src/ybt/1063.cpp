#include <iostream>
using namespace std;
int main() {
  int n, t, mi = 2000, ma = -1; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t > ma) ma = t;
    if (t < mi) mi = t;
  }
  cout << ma - mi << endl;
  return 0;
}
