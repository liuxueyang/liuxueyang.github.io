#include <cstdio>

using ll = long long;

ll qmi(ll a, ll n, ll m) {
  if (a == 0 || m == 1) return 0;
  ll res = 1;
  while (n) {
    if (n & 1) res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}

int main() {
  ll b, p, k;
  scanf("%lld%lld%lld", &b, &p, &k);
  printf("%lld^%lld mod %lld=%lld", b, p, k,
         qmi(b, p, k));
  return 0;
}
