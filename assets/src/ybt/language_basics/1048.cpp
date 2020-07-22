#include <iostream>
using namespace std;
int main() {
  int a, b; cin >> a >> b;
  cout << ((a < 60 && b >= 60) || (b < 60 && a >= 60)) << endl;
  return 0;
}
