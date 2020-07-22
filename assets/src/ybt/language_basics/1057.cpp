#include <iostream>
using namespace std;
int main() {
  int a, b, c; char p; cin >> a >> b >> p;
  switch (p) {
  case '+':
    c = a + b; break;
  case '-': c = a - b; break;
  case '*': c = a * b; break;
  case '/':
    if (b == 0) {
      cout << "Divided by zero!\n"; return 0;
    }
    c = a / b; break;
  default:
    cout << "Invalid operator!\n"; return 0;
  }
  cout << c << endl;
  return 0;
}
