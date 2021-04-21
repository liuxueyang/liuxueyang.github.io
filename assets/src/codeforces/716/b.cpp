#include <cstdio>
#include <cmath>
#include <iostream>

const int MOD = 1e9 + 7;
using ll = unsigned long long;

// TODO:

int main() {
  #ifdef _DEBUG
  freopen("b.in", "r", stdin);
  #endif

  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 1) {
      printf("1\n");
      continue;
    }

    ll x = ll(n) * (n - 1);
    printf("x=%lld\n", x);
    x %= MOD;
    printf("x=%lld\n", x);
    x = x * (((1LL << k) - 1) % MOD) % MOD;
    printf("x=%lld\n", x);
    x = (x + n - 1) % MOD;
    printf("%lld\n", x);
  }

  return 0;
}
