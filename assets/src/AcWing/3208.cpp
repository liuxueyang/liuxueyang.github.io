#include <cstdio>

using namespace std;

const int N = 510;
int a[N][N], n;

int main() {
  #ifdef _DEBUG
  freopen("3208.in", "r", stdin);
  #endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  for (int i = 1; i <= 2*n-1; ++i) {
    if (i & 1) {
      for (int j = i, k = 1; j >= 1; --j, ++k) {
        if (j >= 1 && j <= n && k >= 1 && k <= n) {
          printf("%d ", a[j][k]);
        }
      }
    } else {
      for (int j = 1, k = i; k >= 1; ++j, --k) {
        if (j >= 1 && j <= n && k >= 1 && k <= n) {
          printf("%d ", a[j][k]);
        }
      }
    }
  }
  puts("");

  return 0;
}
