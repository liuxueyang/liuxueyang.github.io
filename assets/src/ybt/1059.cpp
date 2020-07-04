#include <iostream>
using namespace std;
int main() {
  int n, t; cin >> n; double sum = 0; cout.precision(2);
  cout.setf(ios::fixed, ios::floatfield);
  for (int i = 0; i < n; i++) { cin >> t; sum += t; }
  cout << sum / n << endl;
  return 0;
}
