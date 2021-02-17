#include <cstdio>

const int N = 100010;

int primes[N], cnt = 0;
bool st[N];

void get_primes(int n) {
  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) primes[cnt++] = i;
    for (int j = 0; primes[j] <= n / i; ++j) {
      st[primes[j] * i] = true;
      // primes[j] 是 i 的最小质因子，primes[j] 也是 primes[j]*i 的最小质因子
      if (i % primes[j] == 0) break;
      // 若 primes[j] 不是 i 的因子，那么 primes[j] 是 primes[j]*i 的最小质因子
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("15.in", "r", stdin);
  #endif

  get_primes(N);

  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    printf("%s\n", st[x] ? "NO" : "YES");
  }

  return 0;
}
