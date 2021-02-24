#include <cstdio>

using namespace std;

const int N = 20;
using ll = long long;

ll a[N];

int main() {
  #ifdef _DEBUG
  freopen("1044.in", "r", stdin);
  #endif

  int n;
  scanf("%d", &n);
  a[0] = a[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      a[i] += a[i - j] * a[j - 1];
    }
  }
  printf("%lld\n", a[n]);

  return 0;
}
