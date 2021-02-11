#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using VI = vector<int>;
using ll = long long;

VI div(VI& a, int b) {
  VI c;
  ll t = 0;
  for (int i = int(a.size() - 1); i >= 0; --i) {
    t = t * 10 + a[i];
    c.push_back(t / b);
    t %= b;
  }
  reverse(c.begin(), c.end());
  while (c.size() > 1 && !c.back()) c.pop_back();

  return c;
}

int main() {
  #ifdef _DEBUG
  freopen("1011.in", "r", stdin);
  #endif

  string a;
  int b;
  cin >> a >> b;
  VI A, C;
  for (int i = int(a.size() - 1); i >= 0; --i) A.push_back(a[i] - '0');
  C = div(A, b);
  for (int i = int(C.size() - 1); i >= 0; --i) cout << C[i];
  cout << endl;

  return 0;
}
