#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
using ll = unsigned long long;

int main() {
  #ifdef _DEBUG
  freopen("b.in", "r", stdin);
  #endif

  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    ll res = 1;
    while (k--) {
      res = (res * n) % MOD;
    }
    cout << res << endl;
  }

  return 0;
}
