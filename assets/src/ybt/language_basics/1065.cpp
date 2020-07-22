#include <iostream>
using namespace std;
int main() {
  int m, n, r = 0; cin >> m >> n;
  for (int i = m; i <= n; i++) {
    if (i & 1) r += i;
  }
  cout << r << endl;
  return 0;
}
