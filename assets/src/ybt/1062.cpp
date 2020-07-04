#include <iostream>
using namespace std;
int main() {
  int n, t, res = -1; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t; if (t > res) res = t;
  }
  cout << res << endl;
  return 0;
}
