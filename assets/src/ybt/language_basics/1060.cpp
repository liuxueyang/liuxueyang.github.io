#include <iostream>
using namespace std;
int main() {
  int n; double t; cin >> n; double sum = 0; cout.precision(4);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < n; i++) { cin >> t; sum += t; }
  if (n == 0) cout << 0 << endl;
  else cout << sum / n << endl;
  return 0;
}
