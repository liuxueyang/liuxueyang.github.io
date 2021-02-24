#include <cstdio>
#include <cstring>

using ll = long long;
const int N = 1010;

ll f[N];

ll dfs(ll n) {
  if (!n) return f[n] = 0;
  if (n == 1) return f[n] = 1;
  if (f[n] != -1) return f[n];

  ll res = 1;
  for (int i = 1; i * 2 <= n; ++i) {
    res += dfs(i);
  }
  return f[n] = res;
}

int main() {
  #ifdef _DEBUG
  freopen("1028.in", "r", stdin);
  #endif

  int n;
  scanf("%d\n", &n);

  memset(f, -1, sizeof f);
  printf("%lld\n", dfs(n));

  return 0;
}
