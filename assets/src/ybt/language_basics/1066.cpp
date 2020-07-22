#include <iostream>
using namespace std;
int main() {
  int n, m, r = 0; cin >> m >> n;
  for (int i = m; i <= n; i++) {
    if (i % 17 == 0) r += i;
  }
  cout << r << endl;
  return 0;
}
