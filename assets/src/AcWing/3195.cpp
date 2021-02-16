#include <cstdio>

using namespace std;
using ll = long long;

const int N = 1010, MOD = 1e9 + 7;
int C[N][N];

int main() {
  #ifdef _DEBUG
  freopen("3195.in", "r", stdin);
  #endif

  int n;
  scanf("%d", &n);

  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) C[i][j] = 1;
      else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }

  ll res = 0;
  for (int k = 2; k <= n - 2; ++k) {
    res = (res + ll(C[n - 1][k]) * (k - 1) % MOD * (n - k - 1)) % MOD;
  }
  printf("%lld\n", res);

  return 0;
}
