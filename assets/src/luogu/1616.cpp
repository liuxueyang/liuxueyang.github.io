#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 10010, M = 1e7 + 10;
int w[N], c[N], n, V;
ll d[M];

int main() {
  #ifdef _DEBUG
  freopen("1616.in", "r", stdin);
  #endif

  scanf("%d%d", &V, &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", w + i, c + i);
  for (int i = 0; i < n; ++i) {
    for (int v = w[i]; v <= V; ++v) {
      d[v] = max(d[v], d[v - w[i]] + c[i]);
    }
  }
  printf("%lld\n", d[V]);

  return 0;
}
