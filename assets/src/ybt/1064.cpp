#include <iostream>
using namespace std;
int main() {
  int n, r1 = 0, r2 = 0, r3 = 0, t1, t2, t3, s = 0; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t1 >> t2 >> t3;
    r1 += t1; r2 += t2; r3 += t3;
    s += (t1 + t2 + t3);
  }
  cout << r1 << " " << r2 << " " << r3 << " " << s << endl;
  return 0;
}
