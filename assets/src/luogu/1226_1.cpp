#include <cstdio>
#include <cmath>

using namespace std;
using ll = long long;

ll qmi(ll a, ll n, ll m) {
  if (a == 0) return 0;
  if (m == 1) return 0;

  ll ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return ans;
}

int main() {
  #ifdef _DEBUG
  freopen("1226.in", "r", stdin);
  #endif

  ll b, p, k;
  scanf("%lld%lld%lld", &b, &p, &k);
  printf("%lld^%lld mod %lld=%lld\n", b, p, k, qmi(b, p, k));

  return 0;
}
