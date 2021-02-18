#include <cstdio>

using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  #ifdef _DEBUG
  freopen("19.in", "r", stdin);
  #endif

  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", gcd(a, b));

  return 0;
}
