#include <iostream>
using namespace std;
void P(int a, char c) {
  for (int i = 0; i < a; i++) cout << c; cout << endl;
}
void print(int a, char c) {
  if (a == 1) {
    cout << "  " << c << endl;
  } else if (a == 3) {
    cout << " ";
    P(a, c);
  } else if (a == 5) {
    P(a, c);
  }
}
int main() {
  char c; cin >> c;
  print(1, c);
  print(3, c);
  print(5, c);
  print(3, c);
  print(1, c);
  return 0;
}
