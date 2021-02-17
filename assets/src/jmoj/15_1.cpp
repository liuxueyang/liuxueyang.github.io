#include <cstdio>

const int N = 100010;
bool st[N];

void get_primes(int n) {
  st[0] = st[1] = true;
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) {
      for (int j = i << 1; j <= n; j += i)
        st[j] = true;
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
