#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  for (int i = 50; i <= 100; ++i) {
    sum += i;
  }
  cout << "sum: " << sum << endl;

  for (int i = 10; i >= 0; --i) {
    cout << i << ' ';
  }
  cout << endl;

  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; ++i) {
    cout << i << ' ';
  }
  cout << endl;

  return 0;
}
