#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 110, M = 1010;
int c[N], v[N], n, V, d[M];

int main() {
  #ifdef _DEBUG
  freopen("1048.in", "r", stdin);
  #endif

  scanf("%d%d", &V, &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", v + i, c + i);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = V; j >= v[i]; --j) {
      d[j] = max(d[j], d[j - v[i]] + c[i]);
      res = max(res, d[j]);
    }
  }
  printf("%d\n", res);

  return 0;
}
