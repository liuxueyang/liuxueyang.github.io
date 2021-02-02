#include <cstdio>

using namespace std;

using ll = long long;

int b, p, k;

int qmi(ll a, ll n, ll m) {
  if (!a) return 0;
  ll res = 1 % m;
  while (n) {
    if (n & 1) res = (res % m) * a % m;
    a = (a % m) * a % m;
    n >>= 1;
  }
  return res;
}

int main() {
  #ifdef _DEBUG
  freopen("1226.in", "r", stdin);
#endif

  scanf("%d%d%d", &b, &p, &k);
  printf("%d^%d mod %d=%d\n", b, p, k, qmi(b, p, k));

  return 0;
}
