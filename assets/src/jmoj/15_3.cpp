#include <cstdio>

const int N = 100010;
bool st[N];
int n, primes[N], cnt;

void get_primes(int n) {
  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) primes[cnt++] = i;
    for (int j = 0; primes[j] <= n / i; ++j) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}

int main() {
#ifdef _DEBUG
  freopen("15.in", "r", stdin);
#endif

  get_primes(N);

  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    printf("%s\n", st[x] ? "NO" : "YES");
  }

  return 0;
}
