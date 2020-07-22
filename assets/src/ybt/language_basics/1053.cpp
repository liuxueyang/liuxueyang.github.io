#include <iostream>
using namespace std;
int main() {
  int a, b[3]; cin >> b[0]; a = b[0];
  for (int i = 1; i < 3; i++) {
    cin >> b[i];
    if (b[i] > a) a = b[i];
  }
  cout << a << endl;
  return 0;
}
