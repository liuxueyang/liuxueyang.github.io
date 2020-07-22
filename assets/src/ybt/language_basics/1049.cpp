#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  switch (n) {
  case 1:
  case 3:
  case 5:
    cout << "NO\n"; break;
  default:
    cout << "YES\n"; break;
  }
  return 0;
}
