#include <cstdio>

using namespace std;

int euler(int n) {
  int res = n;
  for (int i = 2; i <= n / i; ++i) {
    if (n % i == 0) {
      res = res / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) res = res / n * (n - 1);
  return res;
}

int main() {
  #ifdef _DEBUG
  freopen("2158.in", "r", stdin);
  #endif

  int n;
  scanf("%d", &n);
  int res = 0;
  for (int i = 2; i <= n - 1; ++i) {
    res += euler(i);
  }
  res = res * 2 + 3;
  if (n == 1) res = 0;
  printf("%d\n", res);

  return 0;
}
