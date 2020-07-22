#include <iostream>
using namespace std;
int main() {
  char a; cin >> a;
  cout << ((int(a) & 1) ? "YES" : "NO") << endl;
  return 0;
}
