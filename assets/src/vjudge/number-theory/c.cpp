#include <cstdio>
#include <cstring>

using namespace std;

const int N = 33000;
int primes[N], cnt, eulers[N];
bool st[N];

void get_eulers(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) {
      primes[cnt++] = i;
      eulers[i] = i - 1;
    }
    for (int j = 0; primes[j] <= n / i; ++j) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) {
        eulers[primes[j] * i] = eulers[i] * primes[j];
        break;
      }
      eulers[primes[j] * i] = eulers[i] * (primes[j] - 1);
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("c.in", "r", stdin);
  #endif

  int t;
  scanf("%d", &t);

  get_eulers(N - 10);

  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", eulers[n]);
  }

  return 0;
}
