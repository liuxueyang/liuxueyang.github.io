#include <iostream>
using namespace std;
int main() {
  int k, r1 = 0, r2 = 0, r3 = 0, t; cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> t;
    switch (t) {
    case 1: r1++; break;
    case 5: r2++; break;
    case 10: r3++; break;
    }
  }
  cout << r1 << endl << r2 << endl << r3 << endl;
  return 0;
}
