#include <iostream>
using namespace std;
int main() {
  int a, n, r = 1; cin >> a >> n;
  for (int i = 0; i < n; i++) {
    r *= a;
  }
  cout << r << endl;
  return 0;
}
