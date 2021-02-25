#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5;
int a[N], b[N][25], n, cur, resi, sum;

void dfs(int i, int k) {
  if (k == n) {
    return;
  }
  dfs(i, k + 1);

  if (cur + b[i][k] > sum / 2) {
    return;
  }
  cur += b[i][k];
  resi = max(cur, resi);
  dfs(i, k + 1);
  cur -= b[i][k];
}

int main() {
  #ifdef _DEBUG
  freopen("2392.in", "r", stdin);
  #endif

  for (int i = 0; i < 4; ++i) scanf("%d", a + i);

  int res = 0;
  for (int i = 0; i < 4; ++i) {
    sum = cur = resi = 0;
    n = a[i];
    for (int j = 0; j < a[i]; ++j) {
      scanf("%d", &b[i][j]);
      sum += b[i][j];
    }
    dfs(i, 0);
    res += (sum - resi);
  }
  printf("%d\n", res);

  return 0;
}
