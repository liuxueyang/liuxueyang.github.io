#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
using VI = vector<int>;

bool cmp(VI& a, VI& b) {
  if (a.size() != b.size()) return a.size() > b.size();
  for (int i = 0; i < int(a.size()); ++i) {
    if (a[i] != b[i]) return a[i] > b[i];
  }
  return true;
}

VI sub(VI& a, VI& b) {
  VI c;
  int t = 0;
  for (int i = 0; i < int(a.size()); ++i) {
    t = a[i] - t;
    if (i < b.size()) t = t - b[i];
    c.push_back((t + 10) % 10);
    t = t < 0;
  }

  while (c.size() > 1 && !c.back()) c.pop_back();
  return c;
}

int main() {
  #ifdef _DEBUG
  freopen("2142.in", "r", stdin);
  #endif

  string a, b;
  VI A, B, C;
  cin >> a >> b;
  for (int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
  for (int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0');
  if (cmp(A, B)) {
    C = sub(A, B);
  } else {
    cout << "-";
    C = sub(B, A);
  }
  for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
  cout << endl;

  return 0;
}
