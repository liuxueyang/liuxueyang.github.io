#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

using ll = long long;
const int N = 3e8 + 10, M = 2e7;

bitset<N> st;
int primes[M], cnt;

void get_primes(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!st[i]) primes[cnt++] = (i);
    for (int j = 0; primes[j] <= n / i; ++j) {
      st[primes[j] * i] = true;
      if (i % primes[j] == 0) break;
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("cf113.in", "r", stdin);
  #endif

  int a, b;
  scanf("%d%d", &a, &b);
  get_primes(b);

  int res = 0;

  for (int i = 0; i < cnt; ++i) {
    int x = primes[i];
    if (x >= a && x <= b) {
      if (x == 2) {
        res++;
        continue;
      }
      if (x % 4 == 1) ++res;
    }
  }
  printf("%d\n", res);

  return 0;
}
