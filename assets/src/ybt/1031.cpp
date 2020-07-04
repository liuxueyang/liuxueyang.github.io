#include <iostream>
using namespace std;
void P(int a) {
  if (a == 0) {
    cout << endl; return;
  }
  cout << a % 10;
  P(a / 10);
}
int main() {
  int a; cin >> a; P(a);
  return 0;
}
