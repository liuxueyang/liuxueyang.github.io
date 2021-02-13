#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N][N], n, d[N][N];

int main() {
  #ifdef _DEBUG
  freopen("1216.in", "r", stdin);
  #endif
  
  scanf("%d", &n);
  int res = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      d[i][j] = max(d[i-1][j], d[i-1][j-1]) + a[i][j];
      if (i == n) res = max(res, d[i][j]);
    }
  }
  printf("%d\n", res);
  
  return 0;
}
