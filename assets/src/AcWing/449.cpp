#include <cstdio>

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("449.in", "r", stdin);
  #endif
  int n;
  scanf("%d", &n);

  for (int i = 2; i <= n / i; ++i) {
    if (n % i == 0) {
      printf("%d\n", n / i);
      break;
    }
  }

  return 0;
}
