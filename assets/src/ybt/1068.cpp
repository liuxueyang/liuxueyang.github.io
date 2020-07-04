#include <iostream>
using namespace std;
int main() {
  int N, m, r = 0, t; cin >> N >> m;
  for (int i = 0; i < N; i++) {
    cin >> t; if (t == m) r++;
  }
  cout << r << endl;
  return 0;
}
