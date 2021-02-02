#include <cstdio>

using ll = long long;
const int N = 1010, MOD = 10007;
int d[N][N];

int qmi(ll a, ll n, ll m) {
  ll res = 1 % m;
  while (n) {
    if (n & 1) res =res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}

int main() {
  #ifdef _DEBUG
  freopen("1313.in", "r", stdin);
  #endif

  int a, b, k, n, m;

  scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
  d[0][0] = 1;

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0 || i == j) d[i][j] = 1;
      else d[i][j] = (d[i-1][j-1] + d[i-1][j]) % MOD;
    }
  }

  ll res = d[k][n];
  res = res * qmi(a, n, MOD) % MOD;
  res = res * qmi(b, m, MOD) % MOD;
  printf("%d\n", int(res));

  return 0;
}
