#include <cstdio>

using ll = long long;

// O(sqrt(n))
void divide(ll n) {
  for (int i = 2; i <= n / i; ++i) {
    if (n % i == 0) {
      printf("%d ", i);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) printf("%lld", n);
  puts("");
}

int main() {
  #ifdef _DEBUG
  freopen("20.in", "r", stdin);
  #endif

  ll n;
  scanf("%lld", &n);
  divide(n);

  return 0;
}
