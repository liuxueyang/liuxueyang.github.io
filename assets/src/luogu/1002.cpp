#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 30;
ll a[N][N], d[N][N];
int n, m, cx, cy;

int dir[4][2] = {
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

bool check(int x, int y) {
  return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void mark(int x, int y) {
  for (int i = 0; i < 4; ++i) {
    int x1 = dir[i][0] * x + cx, y1 = dir[i][1] * y + cy;
    if (check(x1, y1)) a[x1][y1] = -1;
  }
}

int main() {
  #ifdef _DEBUG
  freopen("1002.in", "r", stdin);
  #endif

  scanf("%d%d%d%d", &n, &m, &cx, &cy);
  ++n; ++m; ++cx; ++cy;
  if (cx == 1 && cy == 1) {
    printf("0\n"); return 0;
  }

  mark(1, 2); mark(2, 1);
  a[cx][cy] = -1;

  if (a[1][1] == -1) { printf("0\n"); return 0; }

  d[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (check(i-1, j) && a[i-1][j] != -1 && d[i-1][j]) d[i][j] += d[i-1][j];
      if (check(i, j-1) && a[i][j-1] != -1 && d[i][j-1]) d[i][j] += d[i][j-1];
    }
  }

  printf("%lld\n", d[n][m]);

  return 0;
}
