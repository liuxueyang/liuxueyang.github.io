#include <iostream>
using namespace std;
int main() {
  int a; cin >> a;
  if ((a % 100 != 0 && a % 4 == 0) || (a % 400 == 0)) cout << "Y\n";
  else cout << "N\n";
  return 0;
}
