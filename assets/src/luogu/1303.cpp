#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using VI = vector<int>;

VI mul(VI& a, VI& b) {
  VI c;
  int t;
  for (int i = 0; i < int(a.size()); ++i) {
    t = 0;
    for (int j = 0; j < int(b.size()); ++j) {
      t = t + a[i] * b[j];
      if (i + j >= int(c.size())) {
        c.push_back(t % 10);
        t /= 10;
      } else {
        c[i + j] += t;
        t = c[i + j] / 10;
        c[i + j] %= 10;
      }
    }
    if (t) c.push_back(t);
  }
  while (c.size() > 1 && !c.back()) c.pop_back();
  return c;
}

int main() {
  #ifdef _DEBUG
  freopen("1303.in", "r", stdin);
  #endif

  string a, b;
  cin >> a >> b;
  VI A, B, C;
  for (int i = int(a.size() - 1); i >= 0; --i) A.push_back(a[i] - '0');
  for (int i = int(b.size() - 1); i >= 0; --i) B.push_back(b[i] - '0');
  C = mul(A, B);
  for (int i = int(C.size() - 1); i >= 0; --i) cout << C[i];
  cout << endl;

  return 0;
}
