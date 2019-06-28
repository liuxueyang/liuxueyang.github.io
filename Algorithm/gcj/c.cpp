#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  if (a < b) swap(a, b);
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  // #ifdef DEBUG
  // freopen("c.in", "r", stdin);
  // #endif

  int T;
  cin >> T;

  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    int N, L;
    cin >> N >> L;
    vector<int> a(L);
    for (int i = 0; i < L; ++i) {
      cin >> a[i];
    }
    int g = gcd(a[0], a[1]);
    vector<int> b(L + 1);
    b[0] = a[0] / g;
    int t = b[0];
    set<int> b_s;
    b_s.insert(b[0]);
    for (int i = 0; i < L; ++i) {
      b[i+1] = a[i] / t;        // Runtime Error
      b_s.insert(b[i+1]);
      t = b[i+1];
    }
    map<int, char> n_c;
    int p = 0;
    for (auto x : b_s) {
      n_c[x] = p + 'A';
      ++p;
    }
    for (int i = 0; i < L + 1; ++i) {
      cout << n_c[b[i]];
    }
    cout << endl;
  }
  return 0;
}
