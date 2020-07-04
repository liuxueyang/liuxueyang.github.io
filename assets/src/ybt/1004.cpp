#include <iostream>

using namespace std;

int main() {
  char ch; cin >> ch; cout << "  " << ch << endl;
  cout << " ";
  for (int i = 0; i < 3; i++) cout << ch; cout << endl;
  for (int i = 0; i < 5; i++) cout << ch; cout << endl;
  
  return 0;
}
