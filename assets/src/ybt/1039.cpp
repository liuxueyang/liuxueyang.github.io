#include <iostream>
using namespace std;
int main() {
  int n; cin >> n;
  if (n > 0) cout << "positive";
  else if (n == 0) cout << "zero";
  else cout << "negative";
  cout << endl;
  return 0;
}
