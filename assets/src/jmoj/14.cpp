#include <cstdio>

using ll = long long;

bool prime(ll x) {
  if (x == 1) return false;
  for (int i = 2; i <= x / i; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  #ifdef _DEBUG
  freopen("14.in", "r", stdin);
  #endif

  ll n;
  scanf("%lld", &n);
  printf("%s\n", prime(n) ? "YES" : "NO");

  return 0;
}
