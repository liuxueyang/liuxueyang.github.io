#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using VI = vector<int>;

VI Div(VI& a, int b) {
  VI c;
  ll t = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
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
  freopen("1023.in", "r", stdin);
  #endif

  string a;
  int b;
  cin >> a >> b;
  VI A, C;
  for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
  C = Div(A, b);
  for (int i = C.size() - 1; i >= 0; --i) printf("%d", C[i]);
  puts("");

  return 0;
}
